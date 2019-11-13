import itertools
def solution(numbers):
    answer = ''
    num = []
    num2 = []
    for i in range(len(numbers)):
        num.append(str(numbers[i]))
    per = list(map(''.join, itertools.permutations(num)))
    for j in range(len(per)):
        num2.append(int(per[j]))
    num2.sort(reverse=True)
    answer += str(num2[0])
    return answer
