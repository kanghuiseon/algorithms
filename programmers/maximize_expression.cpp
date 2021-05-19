#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long num = 0;
vector<string> ops;
bool check[3];
long long cal(string op, vector<long long> v, vector<char> ope){
    long long ans=0;
    for(int i=0; i<op.size(); i++){
        for(int j=0; j<ope.size(); j++){
            if(op[i] == ope[j]){
                if(ope[j] == '-'){
                    long long result = v[j] - v[j+1];
                    v.erase(v.begin()+j);
                    v.erase(v.begin()+j);
                    ope.erase(ope.begin()+j);
                    v.insert(v.begin()+j, result);
                    j = -1;
                }
                else if(ope[j] == '*'){
                    long long result = v[j] * v[j+1];
                    v.erase(v.begin()+j);
                    v.erase(v.begin()+j);
                    ope.erase(ope.begin()+j);
                    v.insert(v.begin()+j, result);
                    j = -1;
                }
                else if(ope[j] == '+'){
                    long long result = v[j] + v[j+1];
                    v.erase(v.begin()+j);
                    v.erase(v.begin()+j);
                    ope.erase(ope.begin()+j);
                    v.insert(v.begin()+j, result);
                    j = -1;
                }
            }
            
        }
    }
    ans = v[0];
    return ans;
}
void dfs(vector<char> op, string current, int cnt){
    if(cnt == op.size()){
        ops.push_back(current);
        return;
    }
    for(int i=0; i<op.size(); i++){
        if(check[i])
            continue;
        check[i] = true;
        dfs(op, current + op[i], cnt+1);
        check[i] = false;
    }
}
long long solution(string expression) {
    long long answer = -1;
    vector<long long> v;
    vector<char> op;
    vector<char> ope;
    string tmp;
    for(int i=0; i<expression.size(); i++){
        if(expression[i] != '*' && expression[i] != '-' && expression[i] != '+'){
            tmp += expression[i];
        }
        else{
            ope.push_back(expression[i]);
            //만약에 op에 있으면 그냥 넘어가기
            bool flag = false;
            for(auto a: op){
                if(a == expression[i]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                v.push_back(stoi(tmp));
                tmp = "";
                continue;
            }
            
            op.push_back(expression[i]);
            v.push_back(stoi(tmp));
            tmp = "";
        }
    }
    v.push_back(stoi(tmp));
    dfs(op, "", 0);
    for(int i=0; i<ops.size(); i++){
        long long num = cal(ops[i], v, ope);
        answer = max(answer, abs(num));
    }
    return answer;
}
