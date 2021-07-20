#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
vector<string> arr(11);
int check[11][11][11][11];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<tuple<int, int, int, int, int>> q;
tuple<int, int, int> roll(int x, int y, int di, int cnt){
    while(arr[x+dx[di]][y+dy[di]] != '#' && arr[x][y] != 'O'){
        x += dx[di];
        y += dy[di];
        cnt++;
    }
    return make_tuple(x, y, cnt);
}
void bfs(){
    while(!q.empty()){
        int rx = get<0>(q.front());
        int ry = get<1>(q.front());
        int bx = get<2>(q.front());
        int by = get<3>(q.front());
        int count = get<4>(q.front());
        q.pop();
        if(count >= 10)
            continue;
        for(int i=0; i<4; i++){
            tuple<int, int, int> tmpR = roll(rx, ry, i, 0);
            tuple<int, int, int> tmpB = roll(bx, by, i, 0);
            int nrx = get<0>(tmpR), nry = get<1>(tmpR), nrcnt = get<2>(tmpR);
            int nbx = get<0>(tmpB), nby = get<1>(tmpB), nbcnt = get<2>(tmpB);
            if(arr[nbx][nby] == 'O'){
                continue;
            }
            if(arr[nrx][nry] == 'O'){
                printf("1\n");
                return;
            }
            if(nrx == nbx && nry == nby){
                if(nrcnt < nbcnt){
                    nbx -= dx[i];
                    nby -= dy[i];
                }
                else{
                    nrx -= dx[i];
                    nry -= dy[i];
                }
            }
            
            if(check[nrx][nry][nbx][nby] == 1){
                continue;
            }
            check[nrx][nry][nbx][nby] = 1;
            q.push(make_tuple(nrx, nry, nbx, nby, count+1));
        }
        
    }
    printf("0\n");
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int rx=0, ry=0, bx=0, by=0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'R'){
                rx = i;
                ry = j;
            }
            else if(arr[i][j] == 'B'){
                bx = i;
                by = j;
            }
        }
    }
    check[rx][ry][bx][by] = 1;
    q.push(make_tuple(rx, ry, bx, by, 0));
    bfs();
    return 0;
}
