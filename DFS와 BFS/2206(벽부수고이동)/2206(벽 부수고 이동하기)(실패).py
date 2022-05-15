from collections import deque
import sys

input = sys.stdin.readline
xarr = [-1, 1, 0, 0]
yarr = [0, 0, -1, 1]
INF = 1000001
N, M = map(int, input().split())
matrix = [list(map(int, list(input())[:-1])) for _ in range(N)]
vertex = [[[INF, INF] for _ in range(M)] for _ in range(N)]
h = deque()
h.append((1, 0, 0, 0))  # cost, x, y, chance

while len(h) > 0:
    cost, x, y, chance = h.popleft()

    vertex[x][y][chance] = cost
    if x == N - 1 and y == M - 1:
        break
    for tx, ty in zip(xarr, yarr):
        if 0 <= x + tx < N and 0 <= y + ty < M:
            if matrix[x + tx][y + ty] == 0 and vertex[x + tx][y + ty][chance] == INF:
                h.append((cost + 1, x + tx, y + ty, chance))
            elif matrix[x + tx][y + ty] == 1 and chance == 0 and vertex[x + tx][y + ty][1] == INF:
                h.append((cost + 1, x + tx, y + ty, 1))

if min(vertex[N - 1][M - 1]) == INF:
    print(-1)
else:
    print(min(vertex[N - 1][M - 1]))
