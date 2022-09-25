from heapq import heappush, heappop

T = int(input())
for t in range(1, T + 1):
    N = int(input())
    INF = 2147483647
    matrix = [list(map(int, input())) for _ in range(N)]
    costarr = [[INF] * N for _ in range(N)]

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    pq = []
    heappush(pq, (matrix[0][0], 0, 0))
    costarr[0][0] = matrix[0][0]

    while len(pq) > 0:
        cost, x, y = heappop(pq)
        if (x, y) == (N-1, N-1):
            break
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and matrix[nx][ny] + cost < costarr[nx][ny]:
                costarr[nx][ny] = matrix[nx][ny] + cost
                heappush(pq, (costarr[nx][ny], nx, ny))

    print(f"#{t} {costarr[N-1][N-1]}")