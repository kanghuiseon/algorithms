#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#define MAX 1001
using namespace std;
int pipe[MAX];
bool repair[MAX];
int main(){
    int n, l;
    scanf("%d %d", &n, &l);
    for(int i=0; i<n; i++){
        scanf("%d", &pipe[i]);
    }
    int cnt=0;
    sort(pipe, pipe+n);
    for(int i=0; i<n; i++){
        // 안고쳐졌다면
        if(!repair[pipe[i]]){
            for(int j=pipe[i]; j<= min(pipe[i]+l-1,MAX); j++){
                repair[j] = true;
            }
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

