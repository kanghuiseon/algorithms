#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX_INDEX 12
using namespace std;
int n, m, k;
int s2d2[MAX_INDEX][MAX_INDEX];
vector<int> tree[MAX_INDEX][MAX_INDEX];
vector<int> deadTree[MAX_INDEX][MAX_INDEX];
int food[MAX_INDEX][MAX_INDEX];
void spring(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!tree[i][j].empty()){
                sort(tree[i][j].begin(), tree[i][j].end());
                vector<int> newTree;
                for(int k=0; k<tree[i][j].size(); k++){
                    if(food[i][j] - tree[i][j][k] >= 0){
                        food[i][j] -= tree[i][j][k];
                        newTree.push_back(tree[i][j][k]+1);
                    }else{
                        deadTree[i][j].push_back(tree[i][j][k]);
                    }
                }
                tree[i][j] = newTree;
            }
        }
    }
}
void summer(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!deadTree[i][j].empty()){
                for(int k=0; k<deadTree[i][j].size(); k++){
                    food[i][j] += deadTree[i][j][k]/2;
                }
            }
        }
    }
}
void fall(){
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!tree[i][j].empty()){
                for(int k=0; k<tree[i][j].size(); k++){
                    if(tree[i][j][k] % 5 == 0){
                        for(int l=0; l<8; l++){
                            int nx = i + dx[l];
                            int ny = j + dy[l];
                            if(nx < 1 || nx > n || ny < 1 || ny > n)
                                continue;
                            tree[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}
void winter(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            food[i][j] += s2d2[i][j];
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &s2d2[i][j]);
            food[i][j] = 5;
        }
    }
    
    for(int i=0; i<m; i++){
        int x, y, age;
        scanf("%d %d %d", &x, &y, &age);
        tree[x][y].push_back(age);
    }
    while(k--){
        spring();
        summer();
        fall();
        winter();
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!deadTree[i][j].empty())
                    deadTree[i][j].clear();
            }
        }
    }
    
    int answer = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!tree[i][j].empty()){
                for(int k=0; k<tree[i][j].size(); k++){
                    answer++;
                }
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
