#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<string> com;
set<string> combine;
bool check[10];
bool compare(string& a, string& b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;
}
bool checkUnique(vector<vector<string>> relation, string indexs){
    int col = relation[0].size();
    int row = relation.size();
    set<string> tmpset;
    string tmp = "";
    for(int i=0; i<row; i++){
        for(int j=0; j<indexs.size(); j++){
            int num = indexs[j] - '0';
            tmp += relation[i][num];
        }
        tmpset.insert(tmp);
        tmp = "";
    }
    if(tmpset.size() == row){
        return true;
    }
    return false;
}
void combination(int index, string current, int col){
    if(index == col){
        sort(current.begin(), current.end());
        combine.insert(current);
        return;
    }
    for(int i=index; i<com.size(); i++){
        if(!check[i]){
            check[i] = true;
            combination(index+1, current+to_string(i), col);
            check[i] = false;
        }
    }
}
int solution(vector<vector<string>> relation) {
    vector<string> ans;
    int col = relation[0].size();
    for(int i=0; i<col; i++){
        com.push_back(to_string(i));
    }
    // 후보키 후보 combination 하기
    for(int i=2; i<col+1; i++){
        combination(0, "", i);
    }
    vector<string> comb;
    for(auto a: combine){
        comb.push_back(a);
    }
    for(int i=0; i<col; i++){
        comb.push_back(to_string(i));
    }
    sort(comb.begin(), comb.end(), compare);
    for(int i=0; i<comb.size(); i++){
        bool flag = true;
        for(int j=0; j<ans.size(); j++){
            int cnt = 0;
            for(int k=0; k<ans[j].size(); k++){
                int n = comb[i].find(ans[j][k]);
                if(n >= 0){
                    cnt++;
                }
            }
            if(cnt == ans[j].size()){
                flag = false;
            }
            
        }
        if(!flag){
            continue;
        }
        if(checkUnique(relation, comb[i])){
            ans.push_back(comb[i]);
        }
    }
    int answ = ans.size();
    return answ;
}
