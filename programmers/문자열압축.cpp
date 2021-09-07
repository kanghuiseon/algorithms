#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0x7fffffff;
    for(int i=1; i<s.size()/2+1; i++){
        string tmp = s.substr(0,i);
        string str = "";
        int cnt=1;
        for(int j=i; j<s.size(); j+=i){
            if(tmp == s.substr(j, i)){
                cnt++;
            }else{
                if(cnt > 1){
                    str += to_string(cnt);
                }
                str += tmp;
                tmp = s.substr(j, i);
                cnt = 1;
            }
        }
        if(cnt > 1){
            str += to_string(cnt);
        }
        str += tmp;
        int size = str.size();
        answer = min(answer, size);
    }
    return answer;
}

int main(){
    int answer = solution("aabbaccc");
    printf("%d\n", answer);
    return 0;
}
