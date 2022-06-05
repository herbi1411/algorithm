import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, (input().split()))
varr = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    varr[a - 1].append(b - 1)
    varr[b - 1].append(a - 1)
visit = [False] * N
answer = 0
for i in range(N):
    if visit[i]:
        continue
    answer += 1
    q = deque()
    q.append(i)
    visit[i] = True
    while len(q) > 0:
        cur = q.popleft()
        for temp in varr[cur]:
            if not visit[temp]:
                q.append(temp)
                visit[temp] = True
print(answer)