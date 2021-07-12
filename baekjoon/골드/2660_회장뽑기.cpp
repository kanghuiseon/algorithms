#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
bool arr[51][51] = {false, };
bool check[51];
int tmp[51] = {0, };
vector<int> answer;
int score = 0, num = 0;
int n;

void bfs(int a){
    queue<pair<int, int>> q;
    int cnt = 0;
    int num = 0;
    q.push(make_pair(a, cnt));
    check[a] = true;
    while(!q.empty()){
        num = q.front().first;
        cnt = q.front().second;
        q.pop();
        for(int i=1; i<n+1; i++){
            if(!check[i] && arr[num][i]){
                q.push(make_pair(i, cnt+1));
                check[i] = true;
            }
        }
    }
    tmp[a] = cnt;
}
int main(){
    cin >> n;
    while(true){
        int a,b;
        cin >> a >> b;
        if(a == -1 && b == -1)
            break;
        arr[a][b] = true;
        arr[b][a] = true;
    }
    for(int i=1; i<n+1; i++){
        bfs(i);
        memset(check, false, sizeof(check));
    }
    int Min = 0x7fffffff;
    for(int i=1; i<n+1; i++){
        if(Min > tmp[i]){
            Min = tmp[i];
        }
    }
    for(int i=1; i<n+1; i++){
        if(tmp[i] == Min){
            answer.push_back(i);
            num++;
        }
    }
    printf("%d %d\n", Min, num);
    for(int i=0; i<answer.size(); i++){
        printf("%d ", answer[i]);
    }
    return 0;
}

