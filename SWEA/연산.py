from collections import deque

INF = 2147483647
MAXN = 1000001
T = int(input())

for t in range(1, T + 1):
    N, M = map(int, input().split())
    countarr = [INF] * MAXN
    q = deque()
    countarr[N] = 0
    q.append(N)

    while len(q) > 0:
        now = q.popleft()
        val = countarr[now]

        if now == M:
            break

        nextVal = [now + 1, now - 1, now * 2, now - 10]
        for nval in nextVal:
            if 0 < nval < MAXN and countarr[nval] > val + 1:
                countarr[nval] = val + 1
                q.append(nval)

    print(f"#{t} {countarr[M]}")
