#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, m, l;
    vector<int> v;
    scanf("%d %d %d", &n, &m, &l);
    v.push_back(0);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    v.push_back(l);
    sort(v.begin(), v.end());
    int left = 1, right = l-1;
    while(left < right){
        int mid = (left + right)/2;
        int cnt=0;
        for(int i=1; i<v.size(); i++){
            int dist = v[i]-v[i-1];
            cnt += dist/mid;
            if(dist % mid == 0){
                cnt--;
            }
        }
        if(cnt > m){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    printf("%d\n", right);
    return 0;
}

