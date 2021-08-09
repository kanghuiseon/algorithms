#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, m;
    vector<int> arr;
    scanf("%d %d", &n, &m);
    int Max = -1;
    for(int i=0; i<m; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
        Max = max(Max, a);
    }
    int left = 1, right = Max;
    while(left < right){
        int tmpN = n;
        int mid = (left+right)/2;
        bool flag = true;
        for(int i=0; i<arr.size(); i++){
            int num = arr[i]/mid;
            if(num > mid){
                flag = false;
            }
            if(arr[i]%mid == 0){
                tmpN -= num;
            }else{
                tmpN -= num+1;
            }
            if(tmpN < 0){
                flag = false;
            }
        }
        if(!flag){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    printf("%d\n", right);
    return 0;
}
