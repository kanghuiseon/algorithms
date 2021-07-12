#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    int s=0, e=0, Min = 0x7fffffff, sum=0;
    while(s<=e){
        if(sum >= x){
            Min = min(Min, e-s);
            sum -= v[s++];
        }
        else if(e == n)
            break;
        else{
            sum += v[e++];
        }
    }
    if(Min == 0x7fffffff)
        Min = 0;
    printf("%d\n", Min);
    return 0;
}
