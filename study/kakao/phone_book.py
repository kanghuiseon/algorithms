# 1 using two-for
def solution(phone_book):
    answer = True
    for i in range(0,len(phone_book)):
        for k in range(0,len(phone_book)):
            if phone_book[i] == phone_book[k]:
                continue
            num = len(phone_book[i])
            a = phone_book[k]
            pre = a[0:num]
            if phone_book[i] == pre:
                answer = False
            else:
                continue
    return answer

#2 using one-for
def solution(phone_book):
    answer = True
    phone_book.sort()
    for i in range(len(phone_book)-1):
        if phone_book[i] in phone_book[i+1]:
            answer = False
    return answer
