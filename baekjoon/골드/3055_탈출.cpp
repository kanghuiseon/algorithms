#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
#define MAX 51
using namespace std;
int x, y;
char arr[MAX][MAX];
int Min = 0x7fffffff;
queue<pair<int, int>> water;
queue<tuple<int, int, int>> q;
bool check[MAX][MAX];
int waterfull[MAX][MAX] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool flag = false;
int ans = 0;
void waterCheck(){
    while(!water.empty()){
        int bx = water.front().first;
        int by = water.front().second;
        water.pop();
        for(int i=0; i<4; i++){
            int nx = bx + dx[i];
            int ny = by + dy[i];
            if(nx<0 || nx>=x || ny<0 | ny>=y)
                continue;
            if(arr[nx][ny] == '.' && waterfull[nx][ny] == 0){
                water.push(make_pair(nx, ny));
                waterfull[nx][ny] = waterfull[bx][by] + 1;
            }
        }
    }
}
void bfs(){
    while(!q.empty()){
        int bx = get<0>(q.front());
        int by = get<1>(q.front());
        int time = get<2>(q.front());
        q.pop();
        for(int i=0; i<4; i++){
            int nx = bx + dx[i];
            int ny = by + dy[i];
            if(nx<0 || nx>=x || ny<0 | ny>=y)
                continue;
            if(arr[nx][ny] == '.' && !check[nx][ny]){
                if(waterfull[nx][ny] == 0){
                    q.push(make_tuple(nx, ny, time+1));
                    check[nx][ny] = true;
                }
                else if(waterfull[nx][ny] > time + 1){
                    q.push(make_tuple(nx, ny, time+1));
                    check[nx][ny] = true;
                }
            }
            if(arr[nx][ny] == 'D'){
                flag = true;
                ans = time+1;
                return;
            }
        }
    }
}
int main(){
    cin >> x >> y;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'S'){
                q.push(make_tuple(i, j, 0));
                check[i][j] = true;
            }
            else if(arr[i][j] == '*'){
                water.push(make_pair(i, j));
            }
        }
    }
    waterCheck();
    bfs();
    if(flag)
        printf("%d\n", ans);
    else{
        printf("KAKTUS\n");
    }
    return 0;
}
