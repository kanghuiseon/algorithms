#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
char arr[251][251];
bool check[251][251];
int Wolf, Sheep;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void bfs(int r, int c, int X, int Y){
    queue<pair<int, int>> q;
    q.push(make_pair(X, Y));
    int sheep = 0;
    int wolf = 0;
    if(arr[X][Y] == 'v') wolf++;
    if(arr[X][Y] == 'o') sheep++;
    check[X][Y] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > -1 && ny > -1 && nx < r && ny < c && arr[nx][ny] != '#' && !check[nx][ny]){
                check[nx][ny] = true;
                if(arr[nx][ny] == 'v') wolf++;
                if(arr[nx][ny] == 'o') sheep++;
                q.push(make_pair(nx, ny));
            }
            
        }
    }
    if(wolf < sheep)
        Wolf -= wolf;
    else
        Sheep -= sheep;

}
int main(){
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++){
        cin >> arr[i];
        for(int j=0; j<c; j++){
            if(arr[i][j] == 'v') Wolf++;
            if(arr[i][j] == 'o') Sheep++;
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!check[i][j] && (arr[i][j] == 'o' || arr[i][j] == 'v'))
                bfs(r, c, i, j);
        }
    }
    printf("%d %d\n", Sheep, Wolf);
    return 0;
}
