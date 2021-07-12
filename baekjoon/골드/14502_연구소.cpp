#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int v[9][9];
int tmp[9][9];
int Max = 0;
void bfs(int n, int m){
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool check[9][9];
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp[i][j] == 2){
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > -1 && nx < n && ny > -1 && ny < m){
                if(tmp[nx][ny] == 0){
                    tmp[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp[i][j] == 0)
                cnt++;
        }
    }
    if(Max < cnt)
        Max = cnt;
}

void dfs(int cnt, int n, int m){
    if(cnt == 3){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                tmp[i][j] = v[i][j];
            }
        }
        bfs(n, m);
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == 0){
                v[i][j] = 1;
                dfs(cnt+1, n, m);
                v[i][j] = 0;
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int c;
            scanf("%d", &c);
            v[i][j] = c;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == 0){
                v[i][j] = 1;
                dfs(1, n, m);
                v[i][j] = 0;
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}

