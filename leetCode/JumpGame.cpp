class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(cnt < i){
                return false;
            }
            cnt = max(cnt, i+nums[i]);
        }
        return true;
    }
};
