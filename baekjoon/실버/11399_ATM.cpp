#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i=1; i<n+1; i++){
        int a;
        cin >> a;
        arr.push_back(make_pair(a, i));
    }
    sort(arr.begin(), arr.end());
    int sum=arr[0].first;
    int sum2=arr[0].first;
    for(int i=1; i<n; i++){
        sum += arr[i].first;
        sum2 += sum;
    }
    printf("%d\n", sum2);
    return 0;
}
