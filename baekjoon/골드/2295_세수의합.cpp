#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MAX 1004
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
    vector<long long int> v2;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            long long int sum = v[i] + v[j];
            v2.push_back(sum);
        }
    }
    sort(v.rbegin(), v.rend());
    sort(v2.begin(), v2.end());
    bool flag = false;
    for(int i=0; i<v.size(); i++){
        for(int j=i; j<v.size(); j++){
            if(binary_search(v2.begin(), v2.end(), v[i]-v[j])){
                printf("%lld\n", v[i]);
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    return 0;
}

