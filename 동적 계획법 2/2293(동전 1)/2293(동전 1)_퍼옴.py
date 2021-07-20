import sys
input = sys.stdin.readline
N,K = map(int,input().split())
arr = [int(input()) for _ in range(N)]
dp = [0] * (K+1)
dp[0] = 1
for i in range(N):
    for j in range(arr[i],K+1):
        dp[j] += dp[j-arr[i]]

print(dp[K])