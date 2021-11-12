#include <map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mm;
        if(s.size() != t.size()){
            return false;
        }
        for(int i=0; i<s.size(); i++){
            mm[s[i]] += 1;
        }
        
        for(int i=0; i<t.size(); i++){
            if(mm[t[i]] != 0){
                mm[t[i]] -= 1;
            }else{
                return false;
            }
        }
        
        for(auto a: mm){
            if(a.second != 0){
                return false;
            }
        }
        return true;
    }
};
