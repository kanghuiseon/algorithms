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
string arr[51];
bool check[51][51] = {false, };
int result[51][51] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
int n, k, Max=-1;
void bfs(int i, int j){
    check[i][j] = true;
    q.push(make_pair(i, j));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < k){
                if(!check[nx][ny] && arr[nx][ny] == 'L'){
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                    result[nx][ny] = result[x][y] + 1;
                    Max = max(result[nx][ny], Max);
                }
            }
        }
    }
}
int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(arr[i][j] == 'L'){
                bfs(i, j);
                memset(check, false, sizeof(check));
                memset(result, 0, sizeof(result));
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}

