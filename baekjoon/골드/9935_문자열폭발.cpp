#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    vector<char> v;
    int bombSize = s2.size();
    for(int i=0; i<s1.size(); i++){
        v.push_back(s1[i]);
        if(v[v.size()-1] == s2[bombSize-1]){
            bool flag = true;
            for(int j=2; j<=bombSize; j++){
                if(v[v.size()-j] != s2[bombSize-j]){
                    flag = false;
                }
            }
            if(flag){
                v.erase(v.end()-bombSize, v.end());
            }
        }
    }
    if(v.size() == 0){
        printf("FRULA\n");
    }else{
        for(int i=0; i<v.size(); i++){
            printf("%c", v[i]);
        }
        printf("\n");
    }
    
    return 0;
}
