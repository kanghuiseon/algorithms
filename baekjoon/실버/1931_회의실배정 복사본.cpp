#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int ,int>> arr;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(b, a));
    }
    sort(arr.begin(), arr.end());
    int end = arr[0].first;
    int cnt=0;
    for(int i=1; i<n; i++){
        if(end <= arr[i].second){
            cnt++;
            end = arr[i].first;
        }
    }
    printf("%d\n", cnt+1);
    return 0;
}
