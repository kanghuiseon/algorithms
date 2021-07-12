#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
bool solve(int index, string s){
    int siz = s.size();
    if(index == siz/2){
        if(siz%2 == 1){
            return true;
        }
        else{
            if(s[index] == s[index-1])
                return true;
        }
    }
    if(s[index] == s[siz-index-1]){
        if(solve(index+1, s))
            return true;
    }
    return false;
}
int main(){
    string s;
    cin >> s;
    if(s.size()==1){
        printf("1\n");
    }else{
        printf("%d\n",solve(0, s));
    }
    return 0;
}
