N = int(input())
dp = [0] * (N + 1)
tarr = []
parr = []
for i in range(1, N + 1):
    t, p = map(int, input().split())
    tarr.append(t)
    parr.append(p)
for i in range(1, N + 1):
    temp = 0
    for j in range(i):
        if j + tarr[j] == i:
            temp = max(temp, parr[j] + dp[j])
    dp[i] = max(dp[i - 1], temp)
print(dp[N])