N = int(input())
arr = [[False] * 100 for _ in range(100)]

for _ in range(N):
    a, b = map(int,input().split())
    for i in range(10):
        for j in range(10):
            arr[i + a][j + b] = True

ans = 0
for i in range(100):
    for j in range(100):
        if arr[i][j]:
            ans += 1
print(ans)
