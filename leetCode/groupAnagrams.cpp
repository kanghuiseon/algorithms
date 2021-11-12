#include <map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        map<string, vector<string>> mm;
        int idx=0;
        for(auto s: strs){
            sort(s.begin(), s.end());
            mm[s].push_back(strs[idx]);
            idx++;
        }
        
        for(auto m: mm){
            v.push_back(m.second);
        }
        return v;
    }
};
