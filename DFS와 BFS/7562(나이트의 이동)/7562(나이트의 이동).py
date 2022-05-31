import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
dx = [-1, -2, -2, -1, 1, 2, 2, 1]
dy = [-2, -1, 1, 2, 2, 1, -1, -2]

for _ in range(N):
    M = int(input())
    arr = [[False for i in range(M)] for j in range(M)]
    sx, sy = map(int, input().split())
    tx, ty = map(int, input().split())
    q = deque()
    q.append((sx, sy))
    arr[sx][sy] = 0
    while len(q) > 0:
        cx, cy = q.popleft()
        if cx == tx and cy == ty:
            break
        for tdx, tdy in zip(dx, dy):
            nx, ny = cx + tdx, cy + tdy
            if 0 <= nx < M and 0 <= ny < M and not arr[nx][ny]:
                arr[nx][ny] = arr[cx][cy] + 1
                q.append((nx, ny))
    print(arr[tx][ty])
