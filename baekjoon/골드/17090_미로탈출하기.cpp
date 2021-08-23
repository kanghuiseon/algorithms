#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_INDEX 502
#define MAX 0x7fffffff
using namespace std;
char arr[MAX_INDEX][MAX_INDEX];
int dp[MAX_INDEX][MAX_INDEX];
int n, m;
int dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    dp[x][y] = 0;
    int nx, ny;
    switch(arr[x][y]){
        case 'U':
            nx = x-1; ny = y;
            break;
        case 'R':
            nx = x; ny = y+1;
            break;
        case 'D':
            nx = x+1; ny = y;
            break;
        case 'L':
            nx = x; ny = y-1;
            break;
        default:
            nx = -1; ny = -1;
            break;
    }
    dp[x][y] = dfs(nx, ny);
    return dp[x][y];
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int num = dfs(i, j);
            if(num != -1 && num != 0){
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
