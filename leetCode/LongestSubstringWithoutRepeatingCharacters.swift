class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        if s.isEmpty{
            return 0
        }
        var Max = Int.min
        var subString: [Character] = []
        for c in s{
            // 만약에 현재 character이 subString 배열에 존재하면 
            // 그 존재하는 character포함해서 앞에 부분 다 지우기 (subString이므로)
            // 그리고 나서 현재 character 배열에 넣고 Max값 비교해서 더 큰 값 넣기
            // firstIndex(of: c) -> 배열에서 첫번째 c가 있는 배열을 리턴함
            // removeFirst(idx+1) -> 배열에서 첫번째 요소부터 idx+1개의 문자를 삭제
            if let idx = subString.firstIndex(of: c){
                subString.removeFirst(idx+1)
            }
            subString.append(c)
            Max = max(Max, subString.count)
        }
        return Max
    }
}
