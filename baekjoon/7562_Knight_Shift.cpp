#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int dx[8] = {-2, -1, -2, -1, 1, 2, 1, 2};
    int dy[8] = {-1, -2, 1, 2, 2, 1, -2, -1};
    while(n--){
        int l, answer=10000;
        scanf("%d", &l);
        bool check[l][l];
        for(int i=0; i<l; i++){
            for(int j=0; j<l; j++){
                check[i][j] = false;
            }
        }
        queue<tuple<int, int, int>> q;
        int x, y, px, py;
        scanf("%d %d", &x, &y);
        scanf("%d %d", &px, &py);
        if(x == px && y == py){
            printf("%d\n", 0);
            continue;
        }
        q.push(make_tuple(x, y, 0));
        check[x][y] = true;
        while(!q.empty()){
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int cnt = get<2>(q.front());
            q.pop();
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx == px && ny == py){
                    answer = min(answer, cnt+1);
                    continue;
                }
                if(nx>-1 && nx<l && ny>-1 && ny<l && !check[nx][ny]){
                    q.push(make_tuple(nx, ny, cnt+1));
                    check[nx][ny] = true;
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
