N = int(input())
arr = [[-1] * 1001 for _ in range(1001)]
bucket = [0] * N
for k in range(N):
    sx, sy, r, c = map(int, input().split())
    for i in range(r):
        for j in range(c):
            arr[sx + i][sy + j] = k

for i in range(1001):
    for j in range(1001):
        if arr[i][j] != -1:
            bucket[arr[i][j]] += 1

for v in bucket:
    print(v)