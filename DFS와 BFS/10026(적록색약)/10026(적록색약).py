from collections import deque

N = int(input())
matrix = [list(input()) for _ in range(N)]
normal = 0
disable = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

## normal
visit = [[False] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if not visit[i][j]:
            normal += 1
            color = matrix[i][j]
            q = deque()
            q.append((i, j))
            visit[i][j] = True
            while len(q) > 0:
                x, y = q.popleft()
                for tx, ty in zip(dx, dy):
                    nx = x + tx
                    ny = y + ty
                    if 0 <= nx < N and 0 <= ny < N and not visit[nx][ny] and matrix[nx][ny] == color:
                        visit[nx][ny] = True
                        q.append((nx, ny))

## disable
visit = [[False] * N for _ in range(N)]
cdict = {'R': 0, 'G': 0, 'B': 1}
for i in range(N):
    for j in range(N):
        if not visit[i][j]:
            disable += 1
            q = deque()
            color = cdict[matrix[i][j]]
            q.append((i, j))
            visit[i][j] = True
            while len(q) > 0:
                x, y = q.popleft()
                for tx, ty in zip(dx, dy):
                    nx = x + tx
                    ny = y + ty
                    if 0 <= nx < N and 0 <= ny < N and not visit[nx][ny] and cdict[matrix[nx][ny]] == color:
                        q.append((nx, ny))
                        visit[nx][ny] = True
print(normal, disable)