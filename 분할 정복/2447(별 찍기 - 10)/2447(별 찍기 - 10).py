def mark(x, y, num, arr):
    if num > 3:
        nextNum = num // 3
        for i in range(3):
            for j in range(3):
                if i == j == 1:
                    continue
                else:
                    mark(x + i * nextNum, y + j * nextNum, nextNum, arr)
    for i in range(num):
        arr[x + i][y] = 1
        arr[x + i][y + num - 1] = 1
        arr[x][y + i] = 1
        arr[x + num - 1][y + i] = 1


N = int(input())
arr = [[0] * N for _ in range(N)]
mark(0, 0, N, arr)
for i in range(N):
    for j in range(N):
        if arr[i][j] == 1:
            print("*", end="")
        else:
            print(" ", end="")
    print("")