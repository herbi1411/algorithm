import sys

input = sys.stdin.readline

N = int(input())
carr = [list(map(int, input().split())) for _ in range(N)]
dp = [[0, 0, 0] for _ in range(N + 1)]

for i in range(1, N + 1):
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + carr[i - 1][0]
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + carr[i - 1][1]
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + carr[i - 1][2]

print(min(dp[N]))