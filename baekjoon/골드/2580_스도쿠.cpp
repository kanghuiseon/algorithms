#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_INDEX 9

using namespace std;
int arr[MAX_INDEX][MAX_INDEX];
int n, m;
vector<pair<int, int>> zero;
bool checkSquare(int x, int y, int num){
    for(int i=x/3*3; i<x/3*3+3; i++){
        for(int j=y/3*3; j<y/3*3+3; j++){
            if(arr[i][j] == num)
                return false;
        }
    }
        
    return true;
}
bool checkLine(int x, int y, int num){
    // 가로
    for(int i=0; i<9; i++){
        if(arr[x][i] == num){
            return false;
        }
    }
    // 세로
    for(int i=0; i<9; i++){
        if(arr[i][y] == num){
            return false;
        }
    }
    return true;
}
void dfs(int index){
    if(index == zero.size()){
        for(int i=0; i<MAX_INDEX; i++){
            for(int j=0; j<MAX_INDEX; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    for(int i=1; i<10; i++){
        int x = zero[index].first;
        int y = zero[index].second;
        
        if(checkSquare(x, y, i) && checkLine(x, y, i)){
            arr[x][y] = i;
            dfs(index+1);
            arr[x][y] = 0;
        }
    }
}
int main(){
    for(int i=0; i<MAX_INDEX; i++){
        for(int j=0; j<MAX_INDEX; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0){
                zero.push_back(make_pair(i, j));
            }
        }
    }
    
    dfs(0);
    return 0;
}

