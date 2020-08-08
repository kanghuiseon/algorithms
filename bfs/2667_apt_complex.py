n = int(input())
arr = [list(map(int, list(input()))) for _ in range(n)]
check = [[0 for _ in range(n)] for _ in range(n)]

num_of_apt = 0
num_of_apt_complex = 0
num_of_apts = []

dx,dy = [-1, 1, 0, 0], [0, 0, 1, -1]
queue = []

for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            num_of_apt += 1
            arr[i][j] = 0
            check[i][j] = 1
            queue.append((i,j))
            while queue:
                x, y = queue.pop(0)
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if 0<= nx < n and 0<= ny < n:
                        if arr[nx][ny] == 1 and check[nx][ny] == 0:
                            arr[nx][ny] = 0
                            check[nx][ny] = 1
                            num_of_apt += 1
                            queue.append((nx, ny))
            num_of_apts.append(num_of_apt)
            num_of_apt = 0
            num_of_apt_complex += 1

print(num_of_apt_complex)
for i in sorted(num_of_apts):
    print(i)


    
        
     