#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX_INDEX 204
#define MAX 30000000
using namespace std;
int arr[MAX_INDEX][MAX_INDEX];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                arr[i][j] = 0;
            else{
                arr[i][j] = MAX;
            }
        }
    }
    for(int i=0; i<fares.size(); i++){
        int a = fares[i][0], b = fares[i][1], f = fares[i][2];
        arr[a][b] = f;
        arr[b][a] = f;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);

    }
    return answer;
}

