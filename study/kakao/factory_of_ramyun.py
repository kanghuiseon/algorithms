from queue import PriorityQueue
def solution(stock, dates, supplies, k):
    q = PriorityQueue()
    answer = 0
    index=0
    while stock <= k:
        for i in range(index, len(dates)):
            s = supplies[i]
            d = dates[i]
            if(d<=stock):
                q.put(s)
                stock -= d
                index += 1
            else:
                break
        stock += q.get()
        answer += 1
    return answer
