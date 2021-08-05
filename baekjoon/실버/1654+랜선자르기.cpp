#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long int k, n;
    scanf("%lld %lld", &k, &n);
    vector<long long int > arr;
    long long int Max = -1;
    for(int i=0; i<k; i++){
        long long int a;
        scanf("%lld", &a);
        arr.push_back(a);
        Max = max(Max, a);
    }
    long long int left = 0; long long int right = Max+1;
    long long int answer = -1;
    while(left < right){
        long long int mid = (left + right)/2;
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            cnt += arr[i] / mid;
        }
        if(cnt < n){
            right = mid;
        }
        else if(cnt >= n){
            left = mid + 1;
            answer = max(answer, mid);
        }
    }
    printf("%lld\n", answer);
    return 0;
}
