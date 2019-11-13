def solution(array, commands):
    answer = []
    arr = []
    for i in range(len(commands)):
        arr = commands[i]
        one = arr[0]
        two = arr[1]
        sub = array[one-1:two]
        sub.sort()
        k = arr[2]
        answer.append(sub[k-1])
    return answer
 
