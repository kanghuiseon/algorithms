import operator
def solution(N, stages):
    answer = []
    fail = {}
    sfail = []
    stage = [0]*(N+2)
    a = len(stages)
    #set stage value 0
    for i in stages:
        stage[i] += 1

    for j in range(1,N+1):
        if a != 0:
            fail[j] = stage[j]/a
            a -= stage[j]
        elif a == 0:
            fail[j]=0
    #sort reversed
    sfail = sorted(fail.items(),key=operator.itemgetter(1),reverse=True)
    
    for k in sfail:
        answer.append(k[0])
    return answer
