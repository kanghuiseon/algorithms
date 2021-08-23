#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_INDEX 502
using namespace std;
int n;
int arr[MAX_INDEX][MAX_INDEX];
int dp[MAX_INDEX][MAX_INDEX];
// 왼, 오, 위, 아래
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int dfs(int x, int y){
    if(dp[x][y] != 1){
        return dp[x][y];
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n){
            continue;
        }
        if(arr[nx][ny] <= arr[x][y]){
            continue;
        }
        dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
    }
    return dp[x][y];
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
            dp[i][j] = 1;
        }
    }
    int Max = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Max = max(Max, dfs(i, j));
        }
    }
    printf("%d\n", Max);
    return 0;
}
