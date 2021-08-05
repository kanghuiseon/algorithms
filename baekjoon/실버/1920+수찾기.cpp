#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> arr;
bool binary_search(int num){
    int left = 0, right = n;
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == num)
            return true;
        if(arr[mid] <= num){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int a;
        scanf("%d", &a);
        if(binary_search(a)){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
