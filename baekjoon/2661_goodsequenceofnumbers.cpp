#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string num = "123";
vector<string> nums;
int Min = 0x7fffffff;
bool flag = false;
string ans = "";
bool check(string number){
    int end = number.size()-1;
    for(int i=1; i<=number.size()/2; i++){
        string a = number.substr(end-i, i);
        string b = number.substr(end, i);
        if(a.compare(b) == 0){
            return false;
        }
        end--;
    }
    return true;
}

void dfs(int n, string current){
    if(flag)
        return;
    if(!check(current))
        return;
    if(current.size() == n){
        ans = current;
        flag = true;
        return;
    }
    for(int i=0; i<num.size(); i++){
        dfs(n, current + num[i]);
    }
}

int main(){
    int n;
    cin >> n;
    dfs(n, "");
    cout << ans << endl;
    return 0;
}
