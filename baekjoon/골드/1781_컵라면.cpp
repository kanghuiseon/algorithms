#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++){
        int dead, cup;
        cin >> dead >> cup;
        v.push_back(make_pair(dead, cup));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        int dead = v[i].first;
        pq.push(v[i].second);
        if(pq.size() > dead){
            pq.pop();
        }
    }
    int sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    printf("%d\n", sum);
    return 0;
}
