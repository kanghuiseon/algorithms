#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end());
    pq.push(arr[0].second);
    for(int i=1; i<n; i++){
        if(pq.top() > arr[i].first){
            pq.push(arr[i].second);
        }else{
            pq.pop();
            pq.push(arr[i].second);
        }
    }
    printf("%d\n", pq.size());
    return 0;
}
