import sys
from collections import deque

input = sys.stdin.readline


def bfs(index, h, visit, parents, path):
    visit[index] = 1
    h.append(index)
    parents[index] = list(h)
    for val in path[index]:
        if visit[val] == 0:
            bfs(val, h, visit, parents, path)
    h.pop()


N = int(input())
path = [deque() for _ in range(N + 1)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    path[a].append(b)
    path[b].append(a)
M = int(input())
search = [tuple(map(int, input().split())) for _ in range(M)]
parents = dict()
visit = [0] * (N + 1)
h = deque()
bfs(1, h, visit, parents, path)
for a, b in search:
    flag = True
    answer = 0
    for v1 in parents[a][::-1]:
        if not flag:
            break
        for v2 in parents[b]:
            if v1 == v2:
                flag = False
                answer = v1
    print(answer)