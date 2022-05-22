import sys

input = sys.stdin.readline

N = int(input())
arr = [int(input()) for _ in range(N)]
dp = [0] * N
for i in range(N):
    if i == 0:
        dp[i] = arr[i]
    elif i == 1:
        dp[i] = dp[i - 1] + arr[i]
    else:
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1])
print(dp[N - 1])