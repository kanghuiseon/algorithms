#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string tmp;
    int sum = 0;
    bool minus = false;
    for(int i=0; i<s.size()+1; i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '\0'){
            if(minus)
                sum -= stoi(tmp);
            else
                sum += stoi(tmp);
            if(s[i] == '-')
                minus = true;
            tmp.clear();
            continue;
        }
        tmp += s[i];
    }
    printf("%d\n", sum);
    return 0;
}
