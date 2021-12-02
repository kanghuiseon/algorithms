func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var answer: [Int] = []
    for i in nums.enumerated(){
        let num = target - i.element
        let index = nums.firstIndex(of: num)
        if index == i.offset{
            continue
        }
        if index != nil{
            answer.append(i.offset)
            answer.append(index! as Int)
            break
        }
    }
    return answer
}
