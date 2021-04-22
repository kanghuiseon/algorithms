#include <string>
#include <vector>
#include <iostream>
using namespace std;
int Min = 100;
bool checkNum(string a, string b, int n){
    int cnt=0;
    for(int i=0; i<n; i++){
        if(a[i] != b[i])
            cnt++;
    }
    if(cnt==1)
        return true;
    return false;
}

void dfs(int cnt, string target, string current, vector<string>& words, vector<bool>& check){
    if(current == target){
        Min = min(Min, cnt);
        return;
    }
    for(int i=0; i<words.size(); i++){
        if(!check[i] && checkNum(current, words[i], target.size())){
            check[i] = true;
            dfs(cnt+1, target, words[i], words, check);
            check[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    int cnt=0;
    vector<bool> check(51, false);
    for(auto a: words){
        if(target != a){
            cnt++;
        }
    }
    if(cnt==words.size())
        return 0;
    dfs(0, target, begin, words, check);
    if(Min == 100)
        return 0;
    return Min;
}

