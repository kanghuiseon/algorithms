#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<int> arr;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    int Min = 0x7fffffff;
    int a=0, b=0;
    int left = 0, right = arr.size()-1;
    while(left < right){
        if(arr[left] + arr[right] < 0){
            if(Min > abs(arr[left]+arr[right])){
                Min = abs(arr[left] + arr[right]);
                a = arr[left]; b = arr[right];
            }
            left++;
        }
        else if(arr[left] + arr[right] > 0){
            if(Min > abs(arr[left]+arr[right])){
                Min = abs(arr[left] + arr[right]);
                a = arr[left]; b = arr[right];
            }
            right--;
        }
        else{
            printf("%d %d\n", arr[left], arr[right]);
            return 0;
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}
