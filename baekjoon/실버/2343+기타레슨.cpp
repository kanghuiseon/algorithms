#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, m;
    vector<int> arr;
    scanf("%d %d", &n, &m);
    int Max = -1;
    int sum = 0;
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
        Max = max(Max, a);
        sum += a;
    }
    int left = 0, right = Max*n;
    while(left < right){
        int blue = m;
        int mid = (left + right) / 2;
        int s=0; int ss = sum;
        bool flag = true;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > mid){
                flag = false;
            }
            if(s + arr[i] > mid){
                blue--;
                if(blue == 0){
                    break;
                }
                s = arr[i];
                ss -= arr[i];
            }
            else{
                s += arr[i];
                ss -= arr[i];
            }
        }
        if(ss != 0 || !flag){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    printf("%d\n", right);
    return 0;
}
