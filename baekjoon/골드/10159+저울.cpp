#include <iostream>
#include <algorithm>
#include <string>
#define MAX_INDEX 102
#define MAX 200000
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
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(i == j)
                continue;
            if(arr[i][j] == MAX && arr[j][i] == MAX){
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
