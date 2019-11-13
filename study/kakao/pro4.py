def solution(words, queries):
    answer = []
    for q in queries:
        cnt = 0
        if q[0] == "?":
            q = q[::-1]
            for w in words:
                w = w[::-1]
                if len(q) == len(w):
                    st1 = w
                    st2 = q.replace("?","")
                    idx = st1.find(st2)
                    if idx == 0:
                        cnt += 1
                    else:
                        continue
        elif q[0] != "?":
            for w in words:
                if len(q) == len(w):
                    st1 = w
                    st2 = q.replace("?","")
                    idx = st1.find(st2)
                    if idx == 0:
                        cnt += 1
                    else:
                        continue
        answer.append(cnt)
    return answer
