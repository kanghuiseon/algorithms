class Solution {
public:
    vector<vector<int>> result;
    vector<int> can;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        can = candidates;
        solve(candidates.size(),target, 0, {}, 0);
        return result;
    }
    void solve(int num_candidates, int target, int sum, vector<int> current, int start){
        if(sum == target){
            result.push_back(current);
            return;
        }
        if(sum > target){
            return;
        }
        int i;
        for(i=start; i<num_candidates; i++){
            current.push_back(can[i]);
            solve(num_candidates, target, sum+can[i], current, i);
            current.pop_back();
        }
    }
};
