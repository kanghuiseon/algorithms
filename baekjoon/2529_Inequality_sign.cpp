#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
bool check[10];
string Max = "-1";
string Min = "9999999999";
char op[10];
bool isRight(int a, int b, char op){
    if(op == '<')
        return a < b;
    else if(op == '>')
        return a > b;
    return false;
}
void dfs(string answer, int k){
    if(answer.length() == k+1){
        if(Max < answer)
            Max = answer;
        if(Min > answer)
            Min = answer;
    }
    for(int i=0; i<10; i++){
        if(!check[i]){
            if(answer.size() == 0 || isRight(answer[answer.length()-1] - '0', i, op[answer.length()-1])){
                check[i] = true;
                dfs(answer + to_string(i) , k);
                check[i] = false;
            }
        }
    }
}
int main(){
    int k;
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        scanf(" %c", &op[i]);
    }
    dfs("", k);
    printf("%s\n", Max.c_str());
    printf("%s\n", Min.c_str());
    return 0;
}
