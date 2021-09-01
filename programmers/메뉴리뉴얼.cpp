#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<string, int> m;
vector<string> courseCandidate;
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
void dfs(int cnt, string s, string current, int index){
    if(cnt == 0){
        courseCandidate.push_back(current);
        return;
    }
    for(int i=index; i<s.size(); i++){
        dfs(cnt-1, s, current+s[i], i+1);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
    }
    string alpha = "";
    for(int i=0; i<orders.size(); i++){
        for(int j=0; j<orders[i].size(); j++){
            if(alpha.find(orders[i][j]) == string::npos){
                alpha += orders[i][j];
            }
        }
    }
    sort(alpha.begin(), alpha.end());
    for(int i=0; i<course.size(); i++){
        courseCandidate.clear();
        m.clear();
        int courseNum = course[i];
        // 코스 후보 만들기
        dfs(courseNum, alpha, "", 0);
        
        for(int j=0; j<courseCandidate.size(); j++){
            string candidate = courseCandidate[j];
            for(int k=0; k<orders.size(); k++){
                int index=0;
                for(int l=0; l<orders[k].size(); l++){
                    if(orders[k][l] == candidate[index]){
                        index++;
                        // candidate 가 존재하면
                        if(index == courseNum){
                            m[candidate] += 1;
                            break;
                        }
                    }
                }
            }
        }
        vector<pair<string,int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);
        int Max = v[0].second; // 4
        if(Max < 2){
            continue;
        }
        for(auto a: v){
            if(a.second == Max){
                answer.push_back(a.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main(){
    vector<string> answer = solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2,3,4});
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }
    return 0;
}
