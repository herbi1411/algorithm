# 프림 알고리즘

from heapq import heappush, heappop

T = int(input())

for t in range(1, T + 1):
    V, E = map(int, input().split())
    V += 1
    edge = [[] for _ in range(V)]
    visited = [False] * V
    cnt = 0
    ans = 0

    for _ in range(E):
        n1, n2, w = map(int, input().split())
        edge[n1].append((n2, w))
        edge[n2].append((n1, w))

    q = []
    heappush(q, (0, 0))

    while len(q) > 0:
        cost, now = heappop(q)
        if visited[now]:
            continue
        visited[now] = True
        cnt += 1
        ans += cost

        if cnt == V:
            break
        for n, w in edge[now]:
            heappush(q, (w, n))

    print(f"#{t} {ans}")