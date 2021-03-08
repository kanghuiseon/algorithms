class Solution {
public:
    vector<vector<int>> result;

    void solve(int n, int k, vector<int> current, int start){
        if(current.size() == k){
            result.push_back(current);
        }
        for(int i=start; i<n+1; i++){
            current.push_back(i);
            solve(n, k, current, i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(n,k, {}, 1);
        return result;
    }
};
