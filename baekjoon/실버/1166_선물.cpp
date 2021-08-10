#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, l, w, h;
    scanf("%d %d %d %d", &n, &l, &w, &h);
    double left = 0, right = 1e18;
    for(int i=0; i<100000; i++){
        double mid = (left+right)/2;
        if((long long)(l/mid) * (long long)(w/mid) * (long long)(h/mid) < n){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    printf("%.10lf\n", right);
    return 0;
}

