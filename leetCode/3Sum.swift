class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        var answers: [[Int]] = []
        if(nums.count < 3){
            return []
        }
        var numss = nums
        numss.sort()
        for i in 0..<numss.count-2{
            var left = i+1, right = numss.count-1
            while left < right{
                let sum = numss[i] + numss[left] + numss[right]
                if sum == 0{
                    var tmpArr = [numss[i], numss[left], numss[right]].sorted()
                    if !answers.contains(tmpArr){
                        answers.append(tmpArr)
                    }
                    tmpArr.removeAll()
                    left += 1
                    right -= 1
                }else if sum > 0{
                    right -= 1
                }else{
                    left += 1
                }
            }
        }
        return answers
    }
}
