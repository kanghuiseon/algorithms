#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n, l;
    vector<int> f;
    cin >> n >> l;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        f.push_back(a);
    }
    sort(f.begin(), f.end());
    for(int i=0; i<f.size(); i++){
        if(f[i] <= l){
            l += 1;
        }
    }
    cout << l << endl;
    return 0;
}
