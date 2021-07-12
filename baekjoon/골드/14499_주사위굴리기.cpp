#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> di(7, 0);
struct Dice{
    int up=1, down=6, front=5, back=2, left=4, right=3;
};
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
vector<vector<int>> b;
Dice diceRoll(int c, Dice dice){
    if(c==1){
        int down = dice.right;
        int up = dice.left;
        int right = dice.up;
        int left = dice.down;
        dice.down = down;
        dice.up = up;
        dice.right = right;
        dice.left = left;
        return dice;
    }
    else if(c==2){
        int down = dice.left;
        int up = dice.right;
        int left = dice.up;
        int right = dice.down;
        dice.down = down;
        dice.up = up;
        dice.right = right;
        dice.left = left;
        return dice;
    }
    else if(c==3){
        int up = dice.front;
        int down = dice.back;
        int front = dice.down;
        int back = dice.up;
        dice.up = up;
        dice.down = down;
        dice.front = front;
        dice.back = back;
        return dice;
    }
    else if(c==4){
        int up = dice.back;
        int down = dice.front;
        int back = dice.down;
        int front = dice.up;
        dice.up = up;
        dice.down = down;
        dice.back = back;
        dice.front = front;
        return dice;
    }
    return dice;
}
int main(){
    int n, m, x, y, com;
    cin >> n >> m >> x >> y >> com;
    vector<int> command(com);
    vector<vector<int>> board(n, vector<int>(m, 0));
    Dice dice;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    b = board;
    for(int i=0; i<com; i++){
        cin >> command[i];
    }
    for(int i=0; i<command.size(); i++){
        int c = command[i];
        int nx = x + dx[c];
        int ny = y + dy[c];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
            continue;
        }
        dice = diceRoll(c, dice);
        if(board[nx][ny] == 0){
            board[nx][ny] = di[dice.down];
        }
        else{
            di[dice.down] = board[nx][ny];
            board[nx][ny] = 0;
        }
        cout << di[dice.up] << endl;
        x = nx; y = ny;
    }
    return 0;
}
