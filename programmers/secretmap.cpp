#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;
string cal(int num, int n){
    string s = "";
    while(num != 0){
        if(num%2 == 0){
            num /= 2;
            s += " ";
        }
        else{
            num /= 2;
            s += "#";
        }
    }
    if(s.size() != n){
        while(s.size() != n){
            s += " ";
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string ans = "";
    for(int i=0; i<n; i++){
        string a = cal(arr1[i], n);
        string b = cal(arr2[i], n);
        
        for(int j=0; j<n; j++){
            if(a[j] == '#' || b[j] == '#'){
                ans += "#";
            }
            else{
                ans += " ";
            }
        }
        answer.push_back(ans);
        ans = "";
    }
    return answer;
}
