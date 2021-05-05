#include <string>
#include <vector>
#include <math.h>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left = make_pair(3, 0);
    pair<int, int> right = make_pair(3, 2);
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            left = make_pair((numbers[i]-1)/3 ,0);
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            right = make_pair((numbers[i]-3)/3,2);
        }
        else{
            pair<int ,int> now;
            if(numbers[i] == 0){
                now = make_pair(3,1);
            }
            else{
                now = make_pair((numbers[i]-2)/3,1);
            }
            int leftHand = abs(now.first-left.first)+abs(now.second-left.second);
            int rightHand = abs(now.first-right.first)+abs(now.second-right.second);
            if(numbers[i] == 0){
                if(leftHand < rightHand){
                    answer += "L";
                    left = make_pair(3,1);
                }
                else if(leftHand > rightHand){
                    answer += "R";
                    right = make_pair(3,1);
                }
                else{
                    if(hand == "right"){
                        answer += "R";
                        right = make_pair(3,1);
                    }
                    else{
                        answer += "L";
                        left = make_pair(3,1);
                    }
                }          
            }else if(numbers[i] == 2){
                if(leftHand < rightHand){
                    answer += "L";
                    left = make_pair(0,1);
                }
                else if(leftHand > rightHand){
                    answer += "R";
                    right = make_pair(0,1);
                }
                else{
                    if(hand == "right"){
                        answer += "R";
                        right = make_pair(0,1);
                    }
                    else{
                        answer += "L";
                        left = make_pair(0,1);
                    }
                }     
            }
            else if(numbers[i] == 5){
                if(leftHand < rightHand){
                    answer += "L";
                    left = make_pair(1,1);
                }
                else if(leftHand > rightHand){
                    answer += "R";
                    right = make_pair(1,1);
                }
                else{
                    if(hand == "right"){
                        answer += "R";
                        right = make_pair(1,1);
                    }
                    else{
                        answer += "L";
                        left = make_pair(1,1);
                    }
                }     
            }
            else if(numbers[i] == 8){
                if(leftHand < rightHand){
                    answer += "L";
                    left = make_pair(2,1);
                }
                else if(leftHand > rightHand){
                    answer += "R";
                    right = make_pair(2,1);
                }
                else{
                    if(hand == "right"){
                        answer += "R";
                        right = make_pair(2,1);
                    }
                    else{
                        answer += "L";
                        left = make_pair(2,1);
                    }
                }     
            }
        }
    }
    return answer;
}
