#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
string solution(string new_id) {
    // 대문자 제거
    for(int i=0; i<new_id.size(); i++){
        if(isupper(new_id[i])){
            new_id[i] = tolower(new_id[i]);
        }
    }
    // 불필요하 문자 제거
    for(int i=0; i<new_id.size(); i++){
        if(!isalpha(new_id[i]) && new_id[i] != '.' && new_id[i] != '_' && new_id[i] != '-' && !isnumber(new_id[i]-'0')){
            new_id.erase(i, 1);
            i--;
        }
    }
    // 앞, 뒤 '.' 제거
    if(new_id[0] == '.'){
        while(new_id[0] == '.'){
            new_id.erase(new_id.begin());
        }
    }else if(new_id[new_id.size()-1] == '.'){
        while(new_id[new_id.size()-1] == '.'){
            new_id.pop_back();
        }
    }
    
    // 연속되 '.' 제거
    for(int i=0; i<new_id.size()-1; i++){
        if(new_id.empty()){
            break;
        }
        if(new_id[i] == '.'){
            if(new_id[i+1] == '.'){
                new_id.erase(i+1, 1);
            }
        }
    }
    // 비었다면 'a' 추가 || 길이가 15 초과면 15로 맞추기
    if(new_id.empty()){
        new_id += 'a';
    }else if(new_id.size() > 15){ // 6
        while(new_id.size() != 15){
            new_id.pop_back();
        }
    }
    // 맨 뒤에 '.' 제거
    if(new_id[new_id.size()-1] == '.'){
        while(new_id[new_id.size()-1] == '.'){
            new_id.pop_back();
        }
    }
    // 문자열 길이가 2이하면 맨 뒤의 문자를 길이가 3이 될때까지 붙이기
    if(new_id.size() <= 2){
        while(new_id.size() != 3){
            new_id += new_id[new_id.size()-1];
        }
    }
    return new_id;
}

int main(){
    string answer = solution("abcdefghijklmn.p");
    cout << answer << endl;
    return 0;
}
