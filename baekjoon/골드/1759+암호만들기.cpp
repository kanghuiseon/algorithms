#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l,c;
vector<char> arr;
bool check[27];
bool checkIncrease(string s){
    for(int i=0; i<l-1; i++){
        if(s[i] > s[i+1]){
            return false;
        }
    }
    return true;
}
void dfs(int cnt, string s, int index, int cnt1, int cnt2){
    if(cnt == l){
        if(cnt1 <= 0 || cnt2 <= 1){
            return;
        }
        if(!checkIncrease(s)){
            return;
        }
        cout << s << "\n";
        return;
    }
    for(int i=index; i<arr.size(); i++){
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
            cnt1++;
        }
        else{
            cnt2++;
        }
        if(check[arr[i]-'a']){
            if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
                cnt1--;
            }
            else{
                cnt2--;
            }
            continue;
        }
            
        check[arr[i]-'a'] = 1;
        dfs(cnt+1, s+arr[i], i+1, cnt1, cnt2);
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
            cnt1--;
        }
        else{
            cnt2--;
        }
        check[arr[i]-'a'] = 0;
    }
}
int main(){
    scanf("%d %d", &l, &c);
    for(int i=0; i<c; i++){
        char c;
        cin >> c;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
    dfs(0, "", 0, 0, 0);
    return 0;
}
