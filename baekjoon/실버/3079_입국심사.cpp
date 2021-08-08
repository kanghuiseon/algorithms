#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long int n, m;
    scanf("%lld %lld", &n, &m);
    vector<long long int> arr;
    long long int Max = -1;
    for(int i=0; i<n; i++){
        long long int a;
        scanf("%lld", &a);
        Max = max(Max, a);
        arr.push_back(a);
    }
    long long int s = Max*(m/n+1);
    long long int left = 0, right = s;
    while(left < right){
        long long int mid = (left+right)/2;
        long long int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum += mid/arr[i];
        }
        if(sum >= m){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    printf("%lld\n", right);
    return 0;
}
