#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
vector<string> cuttingString(string s, string divide){
    vector<string> v;
    char* tok = strtok((char*)s.c_str(), divide.c_str());
    while(tok){
        v.push_back(tok);
        if(v.back() == "and")
            v.pop_back();
        tok = strtok(NULL, " ");
    }
    return v;
}
// [1,1,1,1,2,4]
vector<vector<string>> infoTable;
vector<vector<string>> queryTable;
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    // 지원자 정보 table로 만들기
    for(int i=0; i<info.size(); i++){
        vector<string> infos = cuttingString(info[i], " ");
        infoTable.push_back(infos);
    }
    // 요청 정보 테이블로 만들기
    for(int i=0; i<query.size(); i++){
        vector<string> queries = cuttingString(query[i], " ");
        queryTable.push_back(queries);
    }
    int cnt = 0;
    for(int i=0; i<queryTable.size(); i++){
        for(int j=0; j<infoTable.size(); j++){
            int k;
            for(k=0; k<infoTable[j].size(); k++){
                if(queryTable[i][k] == "-")
                    continue;
                if(k == infoTable[j].size()-1){
                    if(stoi(queryTable[i][k]) <= stoi(infoTable[j][k])){
                        continue;
                    }
                }
                if(infoTable[j][k] != queryTable[i][k]){
                    break;
                }
            }
            if(k == infoTable[j].size()){
                cnt++;
            }
        }
        answer.push_back(cnt);
        cnt=0;
    }
    return answer;
}


int main(){
    vector<int> answer = solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"}, {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});
    return 0;
}
