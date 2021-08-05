#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<int> arr;
    scanf("%d", &n);
    int Max = -1;
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
        Max = max(Max, a);
    }
    int total;
    scanf("%d", &total);
    int left = 0, right = Max;
    int diff=0x7fffffff, diffNum = 0x7fffffff;
    while(left <= right){
        int mid = (left + right)/2;
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= mid){
                sum += arr[i];
            }
            else{
                sum += mid;
            }
        }
        if(total < sum){
            right = mid - 1;
        }
        else{
            if(diff > total - sum){
                diff = total - sum;
                diffNum = mid;
            }
            left = mid + 1;
        }
    }
    printf("%d\n", diffNum);
    return 0;
}
