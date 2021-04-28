#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int Max = -1;
    vector<int> dp(1001);
    vector<int> arr(1001);
    for(int i=1; i<n+1; i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for(int i=1; i<n+1; i++){
        Max = max(dp[i], Max);
    }
    printf("%d\n", Max);
    
    return 0;
}

