#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m;
bool checkFit(int x, int y, vector<vector<int>> k, vector<vector<int>> b){
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            b[x+i][y+j] += k[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(b[i+m-1][j+m-1] != 1){
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> rotate90(vector<vector<int>> k){
    vector<vector<int>> tmp(m, vector<int>(m));
    int idx = m-1;
    for(int i=0; i<m; i++){
        vector<int> a = k[i];
        for(int j=0; j<m; j++){
            tmp[j][idx] = a[j];
        }
        idx--;
    }
    return tmp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = lock.size();
    m = key.size();
    bool answer = false;
    vector<vector<int>> board(n+m*2-2, vector<int>(n+m*2-2,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i+m-1][j+m-1] = lock[i][j];
        }
    }
    for(int r=0; r<4; r++){
        for(int i=0; i<n+m-1; i++){
            for(int j=0; j<n+m-1; j++){
                if(checkFit(i, j, key, board)){
                    return true;
                }
            }
        }
        key = rotate90(key);
    }
    return answer;
}

