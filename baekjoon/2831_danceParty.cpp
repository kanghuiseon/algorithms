#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
//3
//1600 -1800 -2200
//1700 -1600 1900
int solve(vector<int> a, vector<int> b){
    int cnt=0;
    int maxa = a.size();
    int maxb = b.size();
    int idxa = 0; int idxb = 0;
    while(idxa < maxa && idxb < maxb){
        if(a[idxa] > b[idxb]){
            cnt++;
            idxa++;
            idxb++;
            continue;
        }
        else{
            idxa++;
        }
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    int ans=0;
    vector<int> menM;
    vector<int> menP;
    vector<int> womenM;
    vector<int> womenP;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a<0){
            menM.push_back(abs(a));
        }
        else{
            menP.push_back(a);
        }
    }
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a<0){
            womenM.push_back(abs(a));
        }
        else{
            womenP.push_back(a);
        }
    }
    
    sort(menM.begin(), menM.end());
    sort(womenM.begin(), womenM.end());
    sort(menP.begin(), menP.end());
    sort(womenP.begin(), womenP.end());
    ans += solve(menM, womenP);
    ans += solve(womenM, menP);
    cout << ans << endl;
    return 0;
}
