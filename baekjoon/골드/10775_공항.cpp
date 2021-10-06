#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main() {
    int g, p;
    cin >> g >> p;
    vector<int> gates;
    vector<int> docking(g+1, 0);
    map<int, int> m;
    for(int i=0; i<p; i++){
        int a;
        cin >> a;
        gates.push_back(a);
    }
    for(int i=1; i<=g; i++){
        m[i] = i;
    }
    int answer = 0;
    for(int i=0; i<p; i++){
        int num = gates[i];
        bool flag = false;
        for(int j=m[num]; j>0; j--){
            if(docking[j] == 0){
                docking[j] = 1;
                m[num] = j-1;
                answer++;
                flag = true;
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    printf("%d\n", answer);
    return 0;
}
