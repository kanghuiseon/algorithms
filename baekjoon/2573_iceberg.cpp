#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
#define MAX 301
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;
int arr[MAX][MAX];
int tmpArr[MAX][MAX];
int ans = 0;
queue<pair<int, int>> q;
queue<pair<int, int>> tmp;
bool visit[MAX][MAX];

void bfs(int x, int y){
    tmp.push(make_pair(x, y));
    while(!tmp.empty()){
        int x = tmp.front().first;
        int y = tmp.front().second;
        visit[x][y] = true;
        tmp.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(arr[nx][ny]!=0 && !visit[nx][ny]){
                tmp.push(make_pair(nx, ny));
                visit[nx][ny] = true;
            }
        }
    }
}
bool checkTwo(){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] != 0 && !visit[i][j]){
                bfs(i, j);
                cnt++;
                if(cnt>=2)
                    return true;
            }
        }
    }
    return false;
}
bool check(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int cnt = 0;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(arr[nx][ny] == 0){
                cnt++;
            }
        }
        tmpArr[x][y] -= cnt;
        if(tmpArr[x][y] < 0)
            tmpArr[x][y] = 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = tmpArr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] != 0)
                return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            cin >> a;
            arr[i][j] = a;
            tmpArr[i][j] = a;
        }
    }
    while(true){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] != 0)
                    q.push(make_pair(i, j));
            }
        }
        if(check()){
            ans++;
            memset(visit, false, sizeof(visit));
            if(checkTwo()){
                break;
            }
        }
        else{
            ans = 0;
            break;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}

