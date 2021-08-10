#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<long long int> v;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        long long int a;
        scanf("%lld", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    long long int Min = 1e18;
    long long int a=0, b=0, c=0;
    for(int i=0; i<n-2; i++){
        long long int mid = v[i];
        int left = i+1;
        int right = n-1;
        while(left < right){
            if(abs(mid + v[left] + v[right]) < Min){
                Min = abs(mid + v[left] + v[right]);
                a=mid; b=v[left]; c=v[right];
            }
            if(mid + v[left] + v[right] < 0){
                left++;
            }
            else if(mid + v[left] + v[right] > 0){
                right--;
            }
            else{
                printf("%lld %lld %lld\n", mid, v[left], v[right]);
                return 0;
            }
        }
    }
    printf("%lld %lld %lld\n", a, b, c);
    return 0;
}

