#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
#define MAX 1000001
using namespace std;
int arr[MAX];
bool check[MAX];
int path[MAX];
int dh[2];
queue<int> q;
void bfs(int f, int s){
    check[s] = true;
    q.push(s);
    while(!q.empty()){
        int h = q.front();
        q.pop();
        for(int i=0; i<2; i++){
            int nh = h + dh[i];
            if(nh >= 1 && nh <= f){
                if(!check[nh]){
                    q.push(nh);
                    check[nh] = true;
                    path[nh] = path[h] + 1;
                }
                
            }
        }
    }
}
int main(){
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    dh[0] = u; dh[1] = -d;
    path[s] = 0;
    bfs(f, s);
    if(check[g])
        printf("%d\n", path[g]);
    else
        printf("use the stairs");
    return 0;
}


