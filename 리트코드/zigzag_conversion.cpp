class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> tmp(numRows);
        bool dir = true;
        string result;
        int idx = 0;
        for(int i=0; i<s.size(); i++){
            if(idx>numRows-1)
                idx--;
            if(idx<0)
                idx++;
            if(dir){
                if(idx==numRows-1){
                    dir = false;
                    tmp[idx].push_back(s[i]);
                    idx--;
                    continue;
                }
                tmp[idx].push_back(s[i]);
                idx++;
                
            }
            else{
                if(idx==0){
                    dir = true;
                    tmp[idx].push_back(s[i]);
                    idx++;
                    continue;
                }
                tmp[idx].push_back(s[i]);
                idx--;
            }
        }
        for(int i=0; i<numRows; i++){
            result += tmp[i];
        }
        
        return result;
    }
};
