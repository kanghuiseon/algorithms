class Solution {
    func maxProduct(_ nums: [Int]) -> Int {
        var minVal = nums[0]
        var maxVal = nums[0]
        var answer = nums[0]
        for i in 1..<nums.count{
            let num1 = nums[i]*minVal, num2 = nums[i]*maxVal
            minVal = min(nums[i], min(num1, num2))
            maxVal = max(nums[i], max(num1, num2))
            answer = max(answer, maxVal)
        }
        return answer
    }
}
