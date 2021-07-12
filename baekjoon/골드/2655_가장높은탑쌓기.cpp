#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> arr;
    vector<int> dp(n+1, 0);
    arr.push_back(make_tuple(0,0,0,0));
    for(int i=0; i<n; i++){
        int a, h, w;
        cin >> a >> h >> w;
        arr.push_back(make_tuple(w, a, h, i+1));
    }
    sort(arr.begin(), arr.end());
    for(int i=1; i<n+1; i++){
        for(int j=0; j<i; j++){
            if(get<1>(arr[j]) < get<1>(arr[i])){
                dp[i] = max(dp[i], get<2>(arr[i])+dp[j]);
            }
        }
    }
    int Max = -1;
    int index = 0;
    for(int i=1; i<n+1; i++){
        if(Max < dp[i]){
            Max = dp[i];
            index = i;
        }
    }
    int num = dp[index];
    index = n;
    vector<int> result;
    while(index!=0){
        if(num == dp[index]){
            result.push_back(get<3>(arr[index]));
            num -= get<2>(arr[index]);
        }
        index--;
    }
    reverse(result.begin(), result.end());
    printf("%d\n", result.size());
    for(int i=0; i<result.size(); i++){
        printf("%d\n", result[i]);
    }
    return 0;
}

