N = 36
lst = []
dx = [-2, -2, -1, -1, 1, 1, 2, 2]
dy = [-1, 1, -2, 2, -2, 2, -1, 1]
visited = [[False] * N for _ in range(N)]
flag = True

for _ in range(N):
    a, b = tuple(input())
    a, b = ord(a) - ord('A'), int(b)
    if visited[a][b] == True:
        flag = False
    else:
        visited[a][b] = True
    lst.append((a, b))

if flag:
    lst.append(lst[0])
    prevX = 0
    prevY = 0
    for i, (x, y) in enumerate(lst):
        if i == 0:
            prevX = x
            prevY = y
            continue

        check = False
        for i in range(8):
            if prevX + dx[i] == x and prevY + dy[i] == y:
                check = True
                break

        if not check:
            flag = False
            break
        else:
            prevX = x
            prevY = y

if flag:
    print("Valid")
else:
    print("Invalid")