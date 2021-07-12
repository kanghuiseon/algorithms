//
//  main.cpp
//  study
//
//  Created by 강희선 on 2021/02/26.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    vector<pair<int, int>> v;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    int end = v[0].first;
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(end <= v[i].second){
            cnt++;
            end = v[i].first;
        }
    }
    printf("%d", cnt);
    
    return 0;
}

