def dfs(x, y):
    if x == M - 1 and y == N - 1:
        return 1
    elif dp[x][y] == -1:
        dp[x][y] = 0
        for k in range(4):
            newx = x + dx[k]
            newy = y + dy[k]
            if 0 <= newx < M and 0 <= newy < N and matrix[newx][newy] < matrix[x][y]:
                dp[x][y] = dp[x][y] + dfs(newx, newy)
    return dp[x][y]


M, N = map(int, input().split())
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
dp = [[-1] * N for _ in range(M)]
matrix = [list(map(int, input().split())) for _ in range(M)]
print(dfs(0, 0))

# print(dp)
# print(matrix)
