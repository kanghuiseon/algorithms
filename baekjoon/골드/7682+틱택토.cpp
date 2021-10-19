#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int arr[3][3];
// 가로, 세로, 대각선 방향으로 3칸 무조건 X가 먼저
// 게임판이 가득 차도 게임 끝
// 게임판의 상태가 틱택토 게임에서 발생할 수 있는 최종 상태인지 판별
// "X" : 1, "O" : 2, "." : 0
//XXXOO.XXX
//XOXOXOXOX
//OXOXOXOXO
//XXOOOXXOX
//XO.OX...X
//.XXX.XOOO
//X.OO..X..
//OOXXXOOXO
//end
vector<string> results;
bool isEnd(){
    // 가로
    int index = 0;
    for(int i=0; i<3; i++){
        if(arr[i][index] != 0 && arr[i][index+1] != 0 && arr[i][index+2] != 0){
            if(arr[i][index] == arr[i][index+1] && arr[i][index+1] == arr[i][index+2]){
                return true;
            }
        }
    }
    // 세로
    for(int i=0; i<3; i++){
        if(arr[index][i] != 0 && arr[index+1][i] != 0 && arr[index+2][i] != 0){
            if(arr[index][i] == arr[index+1][i] && arr[index+1][i] == arr[index+2][i]){
                return true;
            }
        }
    }
    // 왼쪽 대각선
    if(arr[0][0] != 0 && arr[1][1] != 0 && arr[2][2] != 0)
        if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){
            return true;
        }
    // 오른쪽 대각선
    if(arr[0][2] != 0 && arr[1][1] != 0 && arr[2][0] != 0)
        if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]){
            return true;
        }
    return false;
}
string makeString(){
    string tmp;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j] == 0){
                tmp += ".";
            }else if(arr[i][j] == 1){
                tmp += "X";
            }else if(arr[i][j] == 2){
                tmp += "O";
            }
        }
    }
    return tmp;
}
void dfs(int cnt, bool flag){
    // 판을 다 채워도 끝내기
    if(cnt == 9){
        string tmp = makeString();
        results.push_back(tmp);
        return;
    }
    if(isEnd()){
        string tmp = makeString();
        results.push_back(tmp);
        return;
    }
    int current = -1;
    if(flag){
        current = 1; // X
    }else{
        current = 2; // O
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j] == 0){
                arr[i][j] = current;
                dfs(cnt+1, !flag);
                arr[i][j] = 0;
            }
        }
    }
}
int main() {
    dfs(0, true);
    while(1){
        string s;
        cin >> s;
        if(s == "end")
            break;
        bool flag = false;
        for(auto a: results){
            if(s == a){
                flag = true;
                break;
            }
        }
        if(flag){
            printf("valid\n");
        }else{
            printf("invalid\n");
        }
    }
    return 0;
}
