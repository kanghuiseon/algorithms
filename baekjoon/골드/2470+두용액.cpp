#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INDEX 1004
using namespace std;
int main(){
    int n;
    vector<int> v;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int left = 0, right = v.size()-1;
    int a=0, b=0;
    int Min = 0x7fffffff;
    while(left < right){
        if(Min > abs(v[left] + v[right])){
            Min = abs(v[left] + v[right]);
            a = v[left]; b = v[right];
        }
        if(v[left] + v[right] < 0){
            left++;
        }
        else if(v[left] + v[right] > 0){
            right--;
        }
        else{
            printf("%d %d\n", v[left], v[right]);
            return 0;
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}

