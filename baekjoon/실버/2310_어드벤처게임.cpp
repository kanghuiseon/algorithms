#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stack>
#define MAX 1001
using namespace std;
bool answer = false;
vector<int> v[MAX];
bool visited[MAX];
void dfs(int depth, int n, int money){
    if(v[depth][0] == 1 && money < v[depth][1]){
        money = v[depth][1];
    }
    else if(v[depth][0] == -1){
        if(money < v[depth][1]){
            return;
        }
        money -= v[depth][1];
    }
    if(depth == n){
        answer = true;
        return;
    }
    
    visited[depth] = true;
    for(int i=2; i<v[depth].size(); i++){
        if(!visited[v[depth][i]])
            dfs(v[depth][i], n, money);
    }
    visited[depth] = false;
}
int main(){
    while(true){
        for(int i=0; i<MAX; i++){
            v[i].clear();
        }
        int n;
        scanf("%d", &n);
        if(n==0)
            break;
        answer = false;
        for(int i=1; i<n+1; i++){
            char a;
            cin >> a;
            if(a=='E'){
                v[i].push_back(0);
            }
            else if(a == 'L'){
                v[i].push_back(1);
            }
            else if(a == 'T'){
                v[i].push_back(-1);
            }
            int b, c;
            cin >> b >> c;
            v[i].push_back(b);
            while(c!=0){
                v[i].push_back(c);
                cin >> c;
            }
        }
        
        dfs(1, n, 0);
        if(answer){
            cout << "Yes" << endl;
        }
        else{
            cout<< "No" << endl;
        }
    }
    return 0;
}


