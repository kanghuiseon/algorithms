#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n, 0);
    int cnt=0;
    for(int i=0; i<n; i++)
        cin >> v[i];
    int s=0, e=0;
    int sum=0;
    while(true){
        if(sum >= m)
            sum -= v[s++];
        else if(e == n)
            break;
        else
            sum += v[e++];
        if(sum == m)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
