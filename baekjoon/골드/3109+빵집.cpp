#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int r, c;
int check[10003][505];
char arr[10003][505];
// 오대위, 오, 오대아래
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};
bool dfs(int x, int y){
    if(y == c-1){
        return true;
    }
    for(int i=0; i<3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == 'x')
            continue;
        if(check[nx][ny]){
            continue;
        }
        check[nx][ny] = true;
        if(dfs(nx, ny)){
            return true;
        }
    }
    return false;
}
int main() {
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++){
        string s;
        cin >> s;
        for(int j=0; j<c; j++){
            arr[i][j] = s[j];
        }
    }
    int cnt = 0;
    for(int i=0; i<r; i++){
        if(dfs(i, 0)){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
