class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        var arr: [Int] = Array(repeating: 0, count: nums.count)
        arr[0] = nums[0]
        for i in 1..<nums.count{
            if nums[i] < arr[i-1] + nums[i]{
                arr[i] = arr[i-1] + nums[i];
            }else{
                arr[i] = nums[i];
            }
        }
        return arr.max()!
    }
}
