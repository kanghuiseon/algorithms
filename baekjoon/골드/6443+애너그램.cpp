#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int arr[21];
set<string> se;
void dfs(int cnt, string current, string s, int len){
    if(cnt == len){
        cout << current << "\n";
        return;
    }
    for(int i=0; i<len; i++){
        if(arr[i] == 1){
            continue;
        }
        string tmp = current + s[i];
        if(se.find(tmp) != se.end()){
            continue;
        }
        arr[i] = 1;
        se.insert(tmp);
        dfs(cnt+1, tmp, s, len);
        arr[i] = 0;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    vector<string> v;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        dfs(0, "", s, s.size());
        se.clear();
    }
    return 0;
}
