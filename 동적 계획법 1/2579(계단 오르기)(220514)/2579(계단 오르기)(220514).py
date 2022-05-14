N = int(input())
arr = [int(input()) for _ in range(N)]
dp = [[0, 0] for _ in range(300)]

dp[0] = arr[0], arr[0]
if N >= 2:
    dp[1] = arr[1], arr[0] + arr[1]
if N >= 3:
    dp[2] = max(dp[0]) + arr[2], dp[1][0] + arr[2]
for i in range(3, N):
    dp[i] = max(dp[i - 2]) + arr[i], dp[i - 1][0] + arr[i]

print(max(dp[N - 1]))
