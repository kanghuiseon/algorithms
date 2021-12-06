class Solution {
public:
    bool canJump(vector<int>& nums) {
        int Max = 0;
        for(int i=0; i<nums.size(); i++){
            // i번째까지도 못갔다는 말임
            // Max 가 i보다 작다는거는 i전까지의 인덱스에서 i까지 도달할 수 있는 인덱스가 하나도 없었다는 말
            if(Max < i){
                return false;
            }
            Max = max(Max, i+nums[i]);
        }
        return true;
    }
};
