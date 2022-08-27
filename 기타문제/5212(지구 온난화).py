R, C = map(int, input().split())
lst = [list(input()) for _ in range(R)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

sink = []
for i in range(R):
    for j in range(C):
        if lst[i][j] == 'X':
            cnt = 0
            for k in range(4):
                if 0 <= i + dx[k] < R and 0 <= j + dy[k] < C:
                    if lst[i + dx[k]][j + dy[k]] == '.':
                        cnt += 1
                else:
                    cnt += 1
            if cnt >= 3:
                sink.append((i, j))

for i, j in sink:
    lst[i][j] = '.'

sx, sy = R, C
ex, ey = 0, 0

for i in range(R):
    for j in range(C):
        if lst[i][j] == 'X':
            if i <= sx:
                sx = i
            if j <= sy:
                sy = j
            if i >= ex:
                ex = i
            if  j >= ey:
                ey = j

for i in range(sx, ex + 1):
    for j in range(sy, ey + 1):
        print(lst[i][j], end="")
    print()