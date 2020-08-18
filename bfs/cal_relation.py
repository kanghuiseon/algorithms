from collections import defaultdict
n = int(input())
p,q = map(int, input().split())
m = int(input())

arr = defaultdict(set)
for i in range(m):
    x, y = map(int, input().split())
    arr[x].add(y)
    arr[y].add(x)
def bfs(p,q):
    queue, check = [p], {p}
    cnt = -1
    while queue:
        for j in range(len(queue)):
            cur = queue.pop(0)
            if cur == q:
                return cnt+1
            for i in arr[cur]:
                if i not in check:
                    queue.append(i)
                    check.add(i)
        cnt += 1
    return -1
print(bfs(p,q))