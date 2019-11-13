def solution(heights):
    N = len(heights)
    answer = [0]*N
    heights.reverse()
    for h in range(0, len(heights)-1):
        for n in range(h+1, len(heights)):
            if heights[h] < heights[n]:
                answer[h] = (len(heights)-n)
                break
    answer.reverse()
    return answer
