class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> numbers;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=0)
                continue;
            numbers.push_back(nums[i]);
        }
        sort(numbers.begin(), numbers.end());
        int ans=1;
        for(int i=0; i<numbers.size(); i++){
            if(ans == numbers[i])
                ans++;
        }
        return ans;
    }
};
