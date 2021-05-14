#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string num = "";
    vector<string> v;
    int cnt = -1;
    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i] == 'S'){
            v.push_back(num);
            cnt++;
            num = "";
        }
        else if(dartResult[i] == 'D'){
            v.push_back(to_string(pow(stoi(num), 2)));
            cnt++;
            num = "";
        }
        else if(dartResult[i] == 'T'){
            v.push_back(to_string(pow(stoi(num), 3)));
            cnt++;
            num = "";
        }
        else if(dartResult[i] == '*'){
            if(cnt != 0){
                v[cnt-1] = to_string(stoi(v[cnt-1]) * 2);
            }
            v[cnt] = to_string(stoi(v[cnt]) * 2);
        }
        else if(dartResult[i] == '#'){
            v[cnt] = to_string(stoi(v[cnt]) * -1);
        }
        else{
            num += dartResult[i];
        }
    }
    for(int i=0; i<v.size(); i++){
        answer += stoi(v[i]);
    }
    return answer;
}
