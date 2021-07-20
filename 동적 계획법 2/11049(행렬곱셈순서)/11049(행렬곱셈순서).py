n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]
dp = [[0] * n for _ in range(n)]
for i in range(n): #간격
    for j in range(n-i): #index
        for k in range(i-1): #비교
            dp[j][i+j] = arr[j][0] * arr[j][1] # i==0
            dp[j][i+j] = dp[j][j] * arr[j+i][1] # i==1
            dp[j][i+j] = min(dp[j][i+j-1]*arr[i+j][1],arr[j][0] * dp[j+1][i+j]) #i == 2
# 0~1 * 2  0 * 1~2   // 1~2 * 3 2~3 * 1