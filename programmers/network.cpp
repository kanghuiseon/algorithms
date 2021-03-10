#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> com;
int check[201];
bool dfs(int n, int current){
    if(check[current] == 1) return false;
    if(current == com.size()) return false;
    check[current] = 1;
    for(int i=0; i<n; i++){
        if(i==current) continue;
        if(com[current][i] == 1)
            dfs(n, i);
    }
    return true;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    com = computers;
    for(int i=0; i<201; i++){
        check[i] = 0;
    }
    for(int i=0; i<n; i++){
        if(check[i] == 0 && dfs(n,i))
            answer++;
    }
    return answer;
}
