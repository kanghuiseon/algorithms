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
    long long int n;
    scanf("%lld",&n);
    int index = 0;
    stack<pair<long long int, long long int>> s;
    long long int answer[n];
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    while(1){
        if(index == n){
            break;
        }
        
        if(s.empty()){
            s.push(make_pair(index, a[index]));
            answer[index] = 0;
            index++;
            continue;
        }
        if(s.top().second < a[index]){
            s.pop();
//            s.push(make_pair(index, a[index]));
            continue;
        }
        else{
            answer[index] = s.top().first+1;
            s.push(make_pair(index, a[index]));
            index++;

            
        }
        
        
    }
    for(int i=0; i<n; i++){
        printf("%lld ", answer[i]);
    }
    printf("\n");
    return 0;
}
