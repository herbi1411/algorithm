import sys


def dfs(x, y, num, subTotal):
    global dx, dy, N, M, matrix, visit
    if num == 3:
        return matrix[x][y] + subTotal
    rt = 0
    for t in range(4):
        nx = x + dx[t]
        ny = y + dy[t]
        if 0 <= nx < N and 0 <= ny < M and visit[nx][ny] == 0:
            if num == 1:
                visit[nx][ny] = 1
                rt = max(rt, dfs(x, y, num + 1, subTotal + matrix[nx][ny]))
                visit[nx][ny] = 0
            visit[nx][ny] = 1
            rt = max(rt, dfs(nx, ny, num + 1, subTotal + matrix[x][y]))
            visit[nx][ny] = 0
    return rt


input = sys.stdin.readline
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
N, M = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(N)]
visit = [[0] * M for _ in range(N)]
answer = 0
for i in range(N):
    for j in range(M):
        visit[i][j] = 1
        answer = max(answer, dfs(i, j, 0, 0))
        visit[i][j] = 0
print(answer)