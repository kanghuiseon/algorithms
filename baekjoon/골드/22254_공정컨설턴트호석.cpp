#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define MAX_INDEX 100001
using namespace std;
int n, x;
int arr[MAX_INDEX];
bool process(int cnt){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<cnt; i++){
        pq.push(0);
    }
    for(int i=0; i<n; i++){
        int t = pq.top();
        pq.pop();
        pq.push(t+arr[i]);
    }
    int Max = 0;
    while(!pq.empty()){
        Max = pq.top();
        pq.pop();
    }
    if(Max > x){
        return false;
    }else{
        return true;
    }
}
int main(){
    scanf("%d %d", &n, &x);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int left = 1, right = n;
    while(left < right){
        int mid = (left + right)/2;
        if(process(mid)){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    printf("%d\n", right);
    return 0;
}
