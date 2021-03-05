class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(umap.count(diff)){
                return {umap[diff], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
