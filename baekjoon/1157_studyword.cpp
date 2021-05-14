#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;
map<char, int> m;
int main(){
    string a;
    cin >> a;
    for(int i=0; i<a.size(); i++){
        a[i] = toupper(a[i]);
    }
    for(int i=0; i<a.size(); i++){
        m[a[i]] += 1;
    }
    int cnt = 0;
    int Max = -1;
    char ans;
    for(auto s: m){
        if(Max < s.second){
            Max = s.second;
            ans = s.first;
        }
        else if(Max == s.second){
            ans = '?';
        }
    }
    printf("%c\n", ans);
    return 0;
}
