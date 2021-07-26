import sys
input = sys.stdin.readline

N,M = map(int,input().split())
arr = list(map(int,input().split()))
cost = list(map(int,input().split()))
dp = [[0]*(sum(cost)+1) for _ in range(N+1)]
ans = 100000

for i in range(1,N+1):
    for j in range(0,sum(cost)+1):
        dp[i][j] = dp[i-1][j]
        if j < cost[i-1]:
            continue
        else:
            dp[i][j] = max(dp[i][j],dp[i-1][j-cost[i-1]]+arr[i-1])
            if dp[i][j] >= M:
                ans = min(ans,j)

print(ans)