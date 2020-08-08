computer_number = int(input())
connected_number = int(input())

arr = [[0 for i in range(computer_number+1)] for _ in range(computer_number+1)]
check = [0 for _ in range(computer_number+1)]
cnt = 0
for i in range(connected_number):
    first, second = map(int, input().split())
    arr[first][second] = 1
    arr[second][first] = 1


check[1] = 1
queue = [1]

while queue:
    n = queue.pop(0)
    for i in range(1, computer_number+1):
        if arr[n][i] == 1 and check[i] == 0:
            check[i] = 1
            queue.append(i)
            cnt += 1



print(cnt)