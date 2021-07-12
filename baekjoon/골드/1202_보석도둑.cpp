#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewelry;
    vector<int> bags(k);
    priority_queue<int> ans;
    for(int i=0; i<n; i++){
        int m, v;
        cin >> m >> v;
        jewelry.push_back(make_pair(m, v));
    }
    for(int i=0; i<k; i++){
        cin >> bags[i];
    }
    sort(jewelry.begin(), jewelry.end());
    sort(bags.begin(), bags.end());
    long long int sum = 0;
    int idx=0;
    for(int i=0; i<k; i++){
        while(idx<n && jewelry[idx].first <= bags[i]){
            ans.push(jewelry[idx].second);
            idx++;
        }
        if(!ans.empty()){
            sum += (long long int)ans.top();
            ans.pop();
        }
    }
    printf("%lld\n", sum);
    return 0;
}
