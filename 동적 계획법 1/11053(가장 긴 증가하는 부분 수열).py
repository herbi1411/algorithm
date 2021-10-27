import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
dp = [0] * n

for i in range(n):
    val = arr[i]
    smallmax = 0
    for j in range(i-1,-1,-1):
        if arr[j] < val:
            smallmax = max(smallmax,dp[j])

    num = smallmax + 1
    dp[i] = num
print(max(dp))


