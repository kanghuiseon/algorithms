#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v(501, vector<int>(501));
    vector<pair<int, int>> p;
    int a = 0, b=0;
    int cnt = 0;
    string tmp = "";
    for(int i=1; i<s.size()-1; i++){
        if(s[i] != '{' && s[i] != '}' && s[i] != ','){
//            v[a][b] = s[i] - '0';
            tmp += s[i];
        }
        else if(s[i] == ',' && s[i-1] != '}'){
            v[a][b] = stoi(tmp);
            b++;
            cnt++;
            tmp = "";
        }
        else if(s[i] == '}'){
            v[a][b] = stoi(tmp);
            p.push_back(make_pair(cnt, a));
            a++;
            b=0;
            cnt=0;
            tmp = "";
        }
    }
    sort(p.begin(), p.end());
    for(int i=0; i<p.size(); i++){
        int idx = p[i].second;
        for(int j=0; j<v[idx].size(); j++){
            bool flag = false;
            for(auto a: answer){
                if(a == v[idx][j] || v[idx][j] == 0){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                answer.push_back(v[idx][j]);
            }
        }
    }
    return answer;
}

