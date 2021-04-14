#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
#define MAX 1002
int n, m;
int arr[MAX][MAX];
bool check[MAX][MAX];
int answer[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<tuple<int, int, int>> q;

void bfs(int a, int b){
    q.push(make_tuple(a, b, 0));
    check[a][b] = true;
    answer[a][b] = 0;
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > -1 && nx < n && ny > -1 && ny < m){
                if(arr[nx][ny] == 1 && !check[nx][ny]){
                    q.push(make_tuple(nx, ny, cnt+1));
                    answer[nx][ny] = cnt+1;
                    check[nx][ny] = true;
                }
                else if(arr[nx][ny] == 0 && !check[nx][ny]){
                    answer[nx][ny] = 0;
                    check[nx][ny] = true;
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    int x=0, y=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            cin >> a;
            arr[i][j] = a;
            if(a == 2){
                x = i;
                y = j;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!check[i][j] && arr[i][j] == 1)
                answer[i][j] = -1;
        }
    }
    bfs(x, y);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    return 0;
}
