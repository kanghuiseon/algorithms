class Solution {
public:
    vector<string> result;
    void dfs(int dLength, int length, string alpha, vector<string> alphas, int start){
        if(length==dLength){
            result.push_back(alpha);
            return;
        }
        for(int i=start; i<alphas.size(); i++){
            for(int j=0; j<alphas[i].length(); j++){
                string s = alphas[i];
                alpha.push_back(s[j]);
                dfs(dLength, alpha.length(), alpha, alphas, i+1);
                alpha.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> numAlpha = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> alphas;
        for(int i=0; i<digits.length(); i++){
            alphas.push_back(numAlpha[digits[i]-'0']);
        }
        if(digits.length()==0){
            return result;
        }
        dfs(digits.length() ,0, "", alphas, 0);
        return result;
    }
};
