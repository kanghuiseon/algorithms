//
//  main.cpp
//  algoStudy
//
//  Created by 강희선 on 2021/09/29.
//

#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++){
        int num;
        scanf("%d", &num);
        pq.push(num);
    }
    int sum = 0;
    while (pq.size() > 1) {
        int num1 = pq.top(); pq.pop();
        int num2 = pq.top(); pq.pop();
        sum += num1 + num2;
        pq.push(num1+num2);
    }
    printf("%d\n", sum);
    return 0;
}
