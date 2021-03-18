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
    for(int i=1; i<n+1; i++){
        int a;
        scanf("%d", &a);
        v.push_back(make_pair(a, i));
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            sum += v[j].first;
        }
    }
    printf("%d",sum);
    
    return 0;
}

