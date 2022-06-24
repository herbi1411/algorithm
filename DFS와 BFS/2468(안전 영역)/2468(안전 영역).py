from collections import deque

N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
answer = 0
maxv = max([max(l) for l in matrix])
for h in range(maxv + 1):
    temp = 0
    visit = [[False] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if matrix[i][j] > h and not visit[i][j]:
                temp += 1
                q = deque()
                q.append((i, j))
                visit[i][j] = True
                while len(q) > 0:
                    x, y = q.popleft()
                    for tx, ty in zip(dx, dy):
                        nx = x + tx
                        ny = y + ty
                        if 0 <= nx < N and 0 <= ny < N and matrix[nx][ny] > h and not visit[nx][ny]:
                            q.append((nx, ny))
                            visit[nx][ny] = True
    answer = max(answer, temp)
print(answer)