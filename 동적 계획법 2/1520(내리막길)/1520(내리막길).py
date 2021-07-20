M,N = map(int,input().split())
matrix = []
dp = [[0]*N for _ in range(M)];
for i in range(M):
    matrix.append(list(map(int,input().split())))
dp[0][0] = 1

for i in range(M+N-1):
    for j in range(i+1):
        #inspect(j,i-j)
        if j >= M or i-j >= N:
            continue
        else:
            if j-1>=0 and matrix[j-1][i-j] > matrix[j][i-j]:
                dp[j][i-j] += dp[j-1][i-j]
            if i-j-1 >=0 and matrix[j][i-j-1] > matrix[j][i-j]:
                dp[j][i-j] += dp[j][i-j-1]
#print(dp)
for i in range(M+N-1):
    for j in range(i+1):
        #inspect(M-j,N-i+j)
        if M-1-j < 0:
            break
        if N-1-i+j-1 >= 0 and matrix[M-1-j][N-1-i+j-1] < matrix[M-1-j][N-1-i+j]:
            dp[M-1-j][N-1-i+j-1] += dp[M-1-j][N-1-i+j]

#print(dp)
for i in range(M+N-1):
    for j in range(i+1):
        #inspect(j,i-j)
        if j >= M or i-j >= N:
            continue
        else:
            temp = 0
            if j-1>=0 and matrix[j-1][i-j] > matrix[j][i-j]:
                temp += dp[j-1][i-j]
            if i-j-1 >=0 and matrix[j][i-j-1] > matrix[j][i-j]:
                temp += dp[j][i-j-1]
            dp[j][i-j] = max(dp[j][i-j],temp)
#print(dp)
print(dp[M-1][N-1])