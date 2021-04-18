#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
#define MAX 101
using namespace std;
int arr[MAX][MAX];
int tmp[MAX][MAX];
bool check[MAX][MAX];
queue<pair<int, int>> q;
queue<pair<int, int>> qh;
bool checkHole[MAX][MAX];
bool ch[MAX][MAX];
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void Hole(){
    qh.push(make_pair(0, 0));
    checkHole[0][0] = true;
    while(!qh.empty()){
        int x = qh.front().first;
        int y = qh.front().second;
        qh.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;
            if(arr[nx][ny] == 0 && !checkHole[nx][ny]){
                checkHole[nx][ny] = true;
                qh.push(make_pair(nx, ny));
            }
        }
    }
}
int checkBfs(int i, int j){
    int cnt=1;
    queue<pair<int, int>> t;
    t.push(make_pair(i, j));
    ch[i][j] = true;
    while(!t.empty()){
        int x = t.front().first;
        int y = t.front().second;
        t.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;
            if(arr[nx][ny] == 1 && !ch[nx][ny]){
                ch[nx][ny] = true;
                t.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }
    return cnt;
}

int checkNum(){
    int num=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1 && !ch[i][j]){
                num += checkBfs(i, j);
            }
        }
    }
    return num;
}

void bfs(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        check[x][y] = true;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;
            if(arr[nx][ny] == 0 && checkHole[nx][ny]){
                tmp[x][y] = 0;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            cin >> a;
            arr[i][j] = a;
            tmp[i][j] = a;
        }
    }
    int time=0;
    int island = 0;
    while(true){
        // 섬 개수 체크
        memset(checkHole, false, sizeof(checkHole));
        memset(check, false, sizeof(check));
        memset(ch, false, sizeof(ch));
        Hole();
        island = checkNum();
        // 녹이기
        bfs();
        time++;
        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1){
                    flag = true;
                }
            }
            if(flag)
                break;
        }
        if(!flag){
            printf("%d\n%d\n", time, island);
            break;
        }
    }
    
    return 0;
}
