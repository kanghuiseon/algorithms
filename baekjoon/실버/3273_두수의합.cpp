#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n, x;
    cin >> n;
    vector<int> v(n, 0);
    int result=0;
    for(int i=0; i<n; i++)
        cin >> v[i];
    cin >> x;
    int s=0, e=n-1;
    sort(v.begin(), v.end());
    while(s<e){
        if(v[s] + v[e] == x){
            result++;
            e--;
        }
        else if(v[s] + v[e] > x)
            e--;
        else{
            s++;
        }
    }
    printf("%d\n", result);
    return 0;
}
