#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, m;
    vector<int> arr;
    scanf("%d %d", &n, &m);
    int Max = -1;
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
        Max = max(Max, a);
    }
    
    int left = 0, right = Max * n;
    while(left < right){
        int mid = (left + right)/2;
        int price = mid;
        int cnt = 1;
        bool flag = true;
        for(int i=0; i<arr.size(); i++){
            if(mid < Max){
                flag = false;
                break;
            }
            if((price - arr[i]) >= 0){
                price -= arr[i];
            }
            else{
                cnt++;
                price = mid-arr[i];
            }
        }
        if(cnt <= m && flag){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    printf("%d\n", right);
    return 0;
}
