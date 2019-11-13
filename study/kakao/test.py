def solution(answers):
    answer = []
    stu1 = [1,2,3,4,5]
    stu2 = [2,1,2,3,2,4,2,5]
    stu3 = [3,3,1,1,2,2,4,4,5,5]
    ok1=0
    ok2=0
    ok3=0
    com = []
    for i in range(len(answers)):
        if stu1[i%5] == answers[i]:
            ok1 += 1
        if stu2[i%8] == answers[i]:
            ok2 += 1
        if stu3[i%10] == answers[i]:
            ok3 += 1
    com.append(ok1)
    com.append(ok2)
    com.append(ok3)

    maxValue = max(com)
    if maxVlue == ok1:
        answer.append(1)
    if maxValue == ok2:
        answer.append(2)
    if maxValue == ok3:
        answer.append(3)

    answer.sort()
    return answer
