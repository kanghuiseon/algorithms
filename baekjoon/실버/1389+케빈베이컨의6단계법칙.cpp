#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_INDEX 101
#define MAX 101
using namespace std;
int n, m;
int arr[MAX_INDEX][MAX_INDEX];
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = MAX;
        }
    }
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j || i == k || j == k){
                    continue;
                }
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    int sum = 0;
    int Min = 0x7fffffff;
    int node = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j || arr[i][j] == MAX)
                continue;
            sum += arr[i][j];
        }
        if(Min > sum){
            Min = sum;
            node = i;
        }
        sum = 0;
    }
    printf("%d\n", node);
    return 0;
}
