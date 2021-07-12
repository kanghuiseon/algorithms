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
#include <algorithm>

using namespace std;
int maxN = -1, m = 0, n;
void dfs(int sum, int cnt, vector<int>& cards, int start){
    if(sum > m)
        return;
    if(cnt==3){
        if(maxN < sum)
            maxN = sum;
        return;
    }
    for(int i=start; i<n; i++){
        dfs(sum+cards[i], cnt+1, cards, i+1);
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    vector<int> cards;
    for(int i=0; i<n; i++){
        int num;
        scanf("%d", &num);
        cards.push_back(num);
    }
    dfs(0, 0, cards, 0);
    printf("%d\n", maxN);
    return 0;
}

