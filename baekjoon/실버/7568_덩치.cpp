#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;
int dp[MAX];
int arr[MAX];
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    vector<int> result;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(i==j)
                continue;
            int p1W = arr[i].first;
            int p1H = arr[i].second;
            int p2W = arr[j].first;
            int p2H = arr[j].second;
            if(p1W < p2W && p1H < p2H)
                cnt++;
        }
        result.push_back(cnt);
    }
    for(auto a: result)
        printf("%d ", a+1);
    printf("\n");
    return 0;
}

