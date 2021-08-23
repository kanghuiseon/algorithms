#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define MAX_INDEX 51
using namespace std;
int n, m;
int arr[MAX_INDEX][MAX_INDEX];
int dp[MAX_INDEX][MAX_INDEX];
int check[MAX_INDEX][MAX_INDEX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int dfs(int x, int y){
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    for(int i=0; i<4; i++){
        int num = arr[x][y];
        int nx = x + dx[i]*num;
        int ny = y + dy[i]*num;
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 0){
            continue;
        }
        if(check[nx][ny]){
            printf("-1\n");
            exit(0);
        }
        check[nx][ny] = true;
        dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
        check[nx][ny] = false;;
    }
    return dp[x][y];
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++){
            if(s[j] == 'H'){
                arr[i][j] = 0;
            }else{
                arr[i][j] = s[j]-'0';
            }
        }
    }
    
    printf("%d\n", dfs(0, 0)+1);
    return 0;
}
