#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s) {
    int Min = 0x7fffffff;
    if(s.size() == 1){
        Min = 1;
    }
    for(int i=1; i<s.size()/2+1; i++){
        string tmp = s.substr(0, i);
        int cnt = 1;
        string convert = "";
        for(int j=i; j<s.size(); j+=i){
            if(tmp == s.substr(j,i)){
                cnt++;
            }
            else{
                if(cnt > 1)
                    convert += to_string(cnt);
                convert += tmp;
                cnt = 1;
                tmp = s.substr(j, i);
            }
        }
        if(cnt > 1){
            convert += to_string(cnt);
        }
        convert += tmp;
        int size = convert.size();
        Min = min(Min, size);
    }
    return Min;
}
