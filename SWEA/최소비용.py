from heapq import heappush, heappop

INF = 2147483647
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
T = int(input())

for t in range(1, T + 1):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    costarr = [[INF] * N for _ in range(N)]
    q = []

    costarr[0][0] = 0
    heappush(q, (0, 0, 0))

    while len(q) > 0:
        cost, x, y = heappop(q)

        if (x, y) == (N - 1, N - 1):
            break

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                nval = cost + 1 + max(0, arr[nx][ny] - arr[x][y])
                if nval < costarr[nx][ny]:
                    costarr[nx][ny] = nval
                    heappush(q, (nval, nx, ny))

    print(f"#{t} {costarr[N - 1][N - 1]}")