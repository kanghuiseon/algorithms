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
    while(true){
        int num;
        cin >> num;
        if(num==0)
            break;
        string s = to_string(num);
        if(s.size()==1){
            printf("yes\n");
        }else{
            int result = solve(0, s);
            if(result)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}

