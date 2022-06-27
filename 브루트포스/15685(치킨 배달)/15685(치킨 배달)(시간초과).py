from itertools import combinations
from collections import deque


def BFS(matrix, house, N):
    rt = 0
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    for sx, sy in house:
        visit = [[-1] * N for _ in range(N)]
        q = deque()
        q.append((sx, sy))
        visit[sx][sy] = 0
        while len(q) > 0:
            x, y = q.popleft()
            if matrix[x][y] == 2:
                rt += visit[x][y]
                break
            for tx, ty in zip(dx, dy):
                nx = x + tx
                ny = y + ty
                if 0 <= nx < N and 0 <= ny < N and visit[nx][ny] == -1:
                    q.append((nx, ny))
                    visit[nx][ny] = visit[x][y] + 1
    return rt


if __name__ == "__main__":
    N, M = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(N)]
    chicken = []
    house = []
    answer = 987654231
    for i in range(N):
        for j in range(N):
            if matrix[i][j] == 2:
                chicken.append((i, j))
            elif matrix[i][j] == 1:
                house.append((i, j))
    for comb in combinations(chicken, len(chicken) - M):
        for x, y in comb:
            matrix[x][y] = 0
        answer = min(answer, BFS(matrix, house, N))
        for x, y in comb:
            matrix[x][y] = 2
    print(answer)
