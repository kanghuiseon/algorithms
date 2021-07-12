#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int k;
    cin >> k;
    long long int two = 1;
    long long int ans1=0;
    while(two < k){
        two *= 2;
    }
    ans1 = two;
    int cnt = 0;
    while(k>0){
        if(two <= k){
            k -= two;
        }
        else{
            cnt++;
            two /= 2;
        }
    }
    cout << ans1 << " " << cnt << endl;
    return 0;
}

