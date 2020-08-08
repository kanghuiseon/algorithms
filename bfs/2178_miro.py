n, m = map(int, input().split())
arr = [list(map(int, list(input()))) for _ in range(n)]
check = [[0]*m for _ in range(n)]
dx, dy = [-1,1,0,0], [0,0,-1,1]

queue = [(0,0)]
check[0][0] = 1
while queue:
    x,y = queue.pop(0)
    if x == n-1 and y == m-1:
        print(check[x][y])
        break

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < n and 0 <= ny < m:
            if arr[nx][ny] == 1 and check[nx][ny] == 0:
                check[nx][ny] = check[x][y] + 1
                queue.append((nx, ny))