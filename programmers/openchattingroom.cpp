#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<string> parsing(string s){
    vector<string> ans;
    string a = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            ans.push_back(a);
            a = "";
            continue;
        }
        a += s[i];
    }
    ans.push_back(a);
    return ans;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    int n = record.size();
    for(int i=0; i<n; i++){
        if(record[i][0] == 'L'){
            continue;
        }
        vector<string> pars = parsing(record[i]);
        m[pars[1]] = pars[2];
    }
    
    for(int i=0; i<n; i++){
        vector<string> pars = parsing(record[i]);
        if(record[i][0] == 'E'){
            answer.push_back(m[pars[1]] + "님이 들어왔습니다.");
        }
        else if(record[i][0] == 'L'){
            answer.push_back(m[pars[1]] + "님이 나갔습니다.");
        }
        else if(record[i][0] == 'C'){
            continue;
        }
    }
    return answer;
}
int main(){
    vector<string> ans = solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});
    for(int i=0; i<ans.size(); i++){
        printf("%s\n", ans[i].c_str());
    }
    
    return 0;
}
