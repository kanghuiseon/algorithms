#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#define MAX 1001
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a;
        int Min = 0x7fffffff;
        vector<pair<int, int>> v;
        scanf("%d", &a);
        for(int i=0; i<a; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            v.push_back(make_pair(a, b));
        }
        int cnt=0;
        sort(v.begin(), v.end());
        for(int i=0; i<a; i++){
            if(Min > v[i].second){
                Min = v[i].second;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
