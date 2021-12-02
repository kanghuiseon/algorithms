#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        int num = nums[0];
        for(int i=1; i<n; i++){
            answer[i] *= num;
            num *= nums[i];
        }
        num = nums[n-1];
        for(int i=n-2; i>=0; i--){
            answer[i] *= num;
            num *= nums[i];
        }
        return answer;
    }
};
