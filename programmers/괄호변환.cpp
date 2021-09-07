#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
//올바른 문자열인지 체크하기
bool checkRight(string s){
    stack<char> st;
    st.push(s[0]);
    while(true){
        int i;
        for(i=1; i<s.size(); i++){
            if(st.top() == '(' && s[i] == ')'){
                st.pop();
            }else
                st.push(s[i]);

        }
        if(i==s.size())
            break;
    }
    if(st.empty()){
        return true;
    }else{
        return false;
    }
}
// u, v로 나누기
string parenthesis(string p){
    if(p == ""){
        return "";
    }
    int cnt1=0, cnt2=0;
    string u = "", v = "";
    for(int i=0; i<p.size(); i++){
        if(p[i] == '('){
            cnt1++;
            u += "(";
        }else if(p[i] == ')'){
            cnt2++;
            u += ")";
        }
        if(cnt1 == cnt2){
            v = p.substr(cnt1+cnt2);
            break;
        }
    }
    if(checkRight(u)){
        string result = parenthesis(v);
        u += result;
        return u;
    }else{
        string tmp = "(";
        tmp += parenthesis(v);
        tmp += ")";
        u.erase(0, 1);
        u.pop_back();
        string uu = "";
        for(int i=0; i<u.size(); i++){
            if(u[i] == '('){
                uu += ")";
            }else if(u[i] == ')'){
                uu += "(";
            }
        }
        return tmp+uu;
    }
}
string solution(string p) {
    string answer = "";
    answer = parenthesis(p);
    return answer;
}
