#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[101][101];
bool check[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int n, int H, int x, int y){
    if(arr[x][y] <= H)
        return;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > -1 && ny > -1 && nx < n && ny < n && arr[nx][ny] > H && !check[nx][ny]){
            check[nx][ny] = true;
            dfs(n, H, nx, ny);
        }
        
    }
}
int main(){
    int n;
    int minH = 101;
    int maxH = -1;
    int maxCnt = 1;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
            minH = min(minH, arr[i][j]);
            maxH = max(maxH, arr[i][j]);
        }
    }
    for(int i=minH; i<maxH+1; i++){
        int cnt=0;
        memset(check, 0, sizeof(check));
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(arr[j][k] > i && !check[j][k]){
                    dfs(n, i, j, k);
                    cnt++;
                }
            }
        }
        maxCnt = max(maxCnt, cnt);
    }
    printf("%d\n", maxCnt);
    return 0;
}
