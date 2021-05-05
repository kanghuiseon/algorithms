#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    int sizee = board[0].size();
    int num=0;
    for(int i=0; i<sizee; i++){
        if(board[i][moves[0]-1] != 0){
            num = board[i][moves[0]-1];
            board[i][moves[0]-1] = 0;
            break;
        }
    }
    if(num!=0){
        s.push(num);
        
    }
    for(int i=1; i<moves.size(); i++){
        for(int j=0; j<sizee; j++){
            if(board[j][moves[i]-1] != 0){
                int n = board[j][moves[i]-1];
                board[j][moves[i]-1] = 0;
                if(s.empty()){
                    s.push(n);
                    break;
                }
                if(s.top() == n){
                    s.pop();
                    answer++;
                    break;
                }
                else{
                    s.push(n);
                    break;
                }
            }
        }
    }
    answer *= 2;
    return answer;
}
