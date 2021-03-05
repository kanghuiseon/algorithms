class Solution {
public:
    vector<string> result;
    void dfs(string current, int left, int right, int n){
        if(left==n && right == n){
            result.push_back(current);
            return;
        }
        if(left < n){
            dfs(current+'(', left+1, right, n);
        }
        if(right < left){
            dfs(current+')', left, right+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n==1){
            result.push_back("()");
            return result;
        }
        dfs("", 0, 0, n);
        return result;
    }
};
