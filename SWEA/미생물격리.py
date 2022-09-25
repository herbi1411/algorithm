T = int(input())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for t in range(1, T + 1):
    N, M, K = map(int, input().split())
    lst = [[[] for _ in range(N)] for __ in range(N)]
    for _ in range(K):
        x, y, num, direction = map(int, input().split())
        lst[x][y].append((num, direction - 1))

    for _ in range(M):
        temp = [[[] for _ in range(N)] for __ in range(N)]
        for i in range(N):
            for j in range(N):
                for num, direction in lst[i][j]:
                    nx = i + dx[direction]
                    ny = j + dy[direction]
                    temp[nx][ny].append((num, direction))

        for i in range(N):
            for j in range(N):
                if len(temp[i][j]) == 1:
                    if i == 0 or i == N - 1 or j == 0 or j == N - 1:
                        num, direction = temp[i][j][0]
                        num //= 2
                        direction = direction // 2 * 2 + ((direction + 1) % 2)

                        if num == 0:
                            temp[i][j] = []
                        else:
                            temp[i][j] = [(num, direction)]
                elif len(temp[i][j]) >= 2:
                    maxIdx = 0
                    maxNum = 0
                    sumNum = 0
                    for k in range(len(temp[i][j])):
                        num, direction = temp[i][j][k]
                        if num > maxNum:
                            maxIdx = k
                            maxNum = num
                        sumNum += num
                    temp[i][j] = [(sumNum, temp[i][j][maxIdx][1])]

        lst = temp

    ans = 0
    for i in range(N):
        for j in range(N):
            for k in range(len(lst[i][j])):
                ans += lst[i][j][k][0]

    print(f"#{t} {ans}")
