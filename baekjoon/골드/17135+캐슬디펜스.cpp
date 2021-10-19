#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, d;
int arr[20][20];
int archerArr[20];
int tmpArr[20][20];
vector<pair<int, int>> enemies;
int Max = -1;
// 궁수는 성이 있는 곳에만 놔둘 수 있다. 3명
// n+1 모든 칸에 성이 있다.
// 모든 궁수는 동시에 적 공격. 거리가 d 이하인 적만 공격 가능
// 그런 적이 여러명일 경우에는 가장 왼쪽에 있는 적 공격.
// 턴이 끝나면 적은 아래로 한칸씩 이동한다.
// 성이 있는 칸으로 온다면 게임에서 제외된다.
// 모든 적이 격자판에서 나가면 게임 종료.
// 궁수의 공격으로 제거할 수 있는 적의 수를 늘리자.
// 궁수 배치를 dfs로
int calDistance(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}
void moveEnemies(){
    // 적들 한칸씩 아래로 옮기기
    int num = enemies.size();
    int tmpArr2[20][20] = {0,};
    for(int i=0; i<num; i++){
        int ex = enemies[0].first;
        int ey = enemies[0].second;
        if(ex+1 == n+1){
            tmpArr[ex][ey] = 0;
            enemies.erase(enemies.begin(), enemies.begin()+1);
        }else{
            if(tmpArr[ex][ey] == 3){
                tmpArr[ex][ey] = 0;
                enemies.erase(enemies.begin(), enemies.begin()+1);
            }else{
                tmpArr[ex][ey] = 0;
                tmpArr2[ex+1][ey] = 1;
                enemies.push_back(make_pair(ex+1, ey));
                enemies.erase(enemies.begin(), enemies.begin()+1);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(tmpArr2[i][j] == 1){
                tmpArr[i][j] = 1;
            }
        }
    }
}
void moveTmp(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            tmpArr[i][j] = arr[i][j];
            if(arr[i][j] == 1){
                enemies.push_back(make_pair(i, j));
            }
        }
    }
}
// 궁수 놓는 dfs
void dfs(int cnt){
    // 궁수 세명 놓은 상태
    if(cnt == 3){
        int c = 0;
        while(1){
            if(enemies.size() == 0){
                break;
            }
            for(int a=1; a<=m; a++){
                if(archerArr[a] == 0)
                    continue;
                int Min = 0x7fffffff;
                bool flag = false;
                int tmpX = -1, tmpY = -1;
                // 각 적들과 거리 측정하기
                for(int i=0; i<enemies.size(); i++){
                    int ex = enemies[i].first;
                    int ey = enemies[i].second;
                    int distance = calDistance(n+1, a, ex, ey);
                    // 기준 거리 초과하면 계산 x
                    if(distance > d)
                        continue;
                    if(Min > distance){
                        Min = distance;
                        tmpX = ex; tmpY = ey;
                        flag = true;
                    }else if(Min == distance){
                        if(ey < tmpY){
                            tmpX = ex; tmpY = ey;
                        }
                    }
                }
                if(flag && tmpArr[tmpX][tmpY] != 3){
                    tmpArr[tmpX][tmpY] = 3;
                    c++;
                }
            }
            moveEnemies();
        }
        Max = max(Max, c);
        moveTmp();
        return;
    }
    for(int i=1; i<=m; i++){
        if(archerArr[i] == 0){
            archerArr[i] = 1;
            dfs(cnt+1);
            archerArr[i] = 0;
        }
    }
}
int main() {
    cin >> n >> m >> d;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            tmpArr[i][j] = arr[i][j];
            if(arr[i][j] == 1){
                enemies.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0);
    printf("%d\n", Max);
    return 0;
}
