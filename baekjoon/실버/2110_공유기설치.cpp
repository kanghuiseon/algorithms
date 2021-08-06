#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_INDEX 200004
using namespace std;
int main(){
    int n, c;
    scanf("%d %d", &n, &c);
    vector<int> arr;
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int left = 1; int right = arr.back();
    int Max = -1;
    while(left <= right){
        int mid = (left + right)/2;
        int start = arr[0];
        int cnt = 1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-start >= mid){
                start = arr[i];
                cnt++;
            }
        }
        if(cnt >= c){
            left = mid + 1;
            Max = max(Max, mid);
        }
        else{
            right = mid - 1;
        }
    }
    printf("%d\n", Max);
    return 0;
}
