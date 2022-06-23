import sys

input = sys.stdin.readline

N = int(input())
parr = list(map(int, input().split()))
dp = parr[:]

for i in range(N):
    for j in range((i + 1) // 2):
        dp[i] = max(dp[i], dp[j] + dp[i - j - 1])
print(dp[N - 1])