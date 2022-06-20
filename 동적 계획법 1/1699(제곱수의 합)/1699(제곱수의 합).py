from math import sqrt

N = int(input())
dp = [0] * (N + 1)
squareNum = []
for i in range(1, int(sqrt(N) + 1)):
    squareNum.append(i * i)
for i in range(1, N + 1):
    dp[i] = i
    for snum in squareNum:
        if i < snum:
            break
        dp[i] = min(dp[i], dp[i - snum] + 1)
print(dp[N])