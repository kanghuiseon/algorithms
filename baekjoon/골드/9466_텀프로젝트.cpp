#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_INDEX 100005
using namespace std;
int arr[MAX_INDEX];
int visit[MAX_INDEX];
int cycleCheck[MAX_INDEX];
int cnt=0;
void dfs(int start){
    visit[start] = true;
    int next = arr[start];
    if(!visit[next]){
        dfs(next);
    }else if(!cycleCheck[next]){
        for(int i=next; i !=start; i=arr[i])
            cnt++;
        cnt++;
    }
    cycleCheck[start] = true;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        memset(visit, 0, sizeof(visit));
        memset(arr, 0, sizeof(arr));
        memset(cycleCheck, 0, sizeof(cycleCheck));
        cnt = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        
        for(int i=1; i<=n; i++){
            if(visit[i] == 0){
                dfs(i);
            }
        }
        printf("%d\n", n-cnt);
    }
    return 0;
}
