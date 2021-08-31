#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>> minH;
priority_queue<int> maxH;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        if(maxH.empty())
            maxH.push(a);
        else if(minH.size() < maxH.size())
            minH.push(a);
        else
            maxH.push(a);
        
        if(!maxH.empty() && !minH.empty() && maxH.top() > minH.top()){
            int a = maxH.top(); maxH.pop();
            int b = minH.top(); minH.pop();
            maxH.push(b); minH.push(a);
        }
        printf("%d\n", maxH.top());
    }
    return 0;
}
