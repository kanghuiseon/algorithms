class Solution {
public:
    vector<vector<int>> result;
    vector<int> num;
    void dfs(int total, vector<int> current){
        if(current.size() == total){
            result.push_back(current);
            return;
        }
        for(int i=0; i<num.size(); i++){
            if(count(current.begin(), current.end(), num[i])) continue;
            current.push_back(num[i]);
            dfs(total, current);
            current.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        num = nums;
        dfs(nums.size(), {});
        return result;
    }
};
