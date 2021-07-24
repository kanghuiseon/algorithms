#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#define MAX_INDEX 22
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int arr[MAX_INDEX][MAX_INDEX];
int check[MAX_INDEX][MAX_INDEX];
int n;
int ssize = 2;
int eat = 0;
int tt = 0;
vector<pair<int, pair<int, int>>> eating;
queue<pair<int, pair<int, int>>> q;
void bfs(int x, int y){
    q.push(make_pair(0, make_pair(x, y)));
    check[x][y] = 1;
    while(!q.empty()){
        int t = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] > ssize || check[nx][ny]){
                continue;
            }
            check[nx][ny] = 1;
            if(arr[nx][ny] < ssize && arr[nx][ny] != 0){
                eating.push_back(make_pair(t+1, make_pair(nx, ny)));
            }
            else if(arr[nx][ny] == ssize || arr[nx][ny] == 0){
                q.push(make_pair(t+1, make_pair(nx, ny)));
            }
        }
    }
}
int main(){
    pair<int, int> babyShark;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a;
            scanf("%d",&a);
            arr[i][j] = a;
            if(a == 9){
                babyShark.first = i;
                babyShark.second = j;
                check[i][j] = 1;
                arr[i][j] = 0;
            }
        }
    }
    while(true){
        eating.clear();
        bfs(babyShark.first, babyShark.second);
        sort(eating.begin(), eating.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                check[i][j] = 0;
            }
        }
        // 먹을게 있으면
        if(!eating.empty()){
            eat++;
            if(eat == ssize){
                ssize++;
                eat = 0;
                
            }
            tt += eating[0].first;
            arr[eating[0].second.first][eating[0].second.second] = 0;
            babyShark.first = eating[0].second.first;
            babyShark.second = eating[0].second.second;
            
        }
        else{
            break;
        }
    }
    printf("%d\n", tt);
    return 0;
}
