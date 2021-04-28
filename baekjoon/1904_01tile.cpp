#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(1000001);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for(int i=4; i<n+1; i++){
        arr[i] = (arr[i-1]+arr[i-2])%15746;
    }
    printf("%d\n", arr[n]);
    return 0;
}

