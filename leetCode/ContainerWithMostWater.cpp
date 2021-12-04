class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int answer = -1;
        while(left < right){
            int idx = right-left;
            int min = height[left] < height[right] ? height[left] : height[right];
            int width = idx*min;
            answer = answer < width ? width : answer;
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
        }
        return answer;
    }
};
