def recur(a, b, c):
    global dp
    if dp[a + 50][b + 50][c + 50] != False:
        return dp[a + 50][b + 50][c + 50]
    rt = False
    if a <= 0 or b <= 0 or c <= 0:
        rt = 1
    elif a > 20 or b > 20 or c > 20:
        rt = recur(20, 20, 20)
    elif a < b < c:
        rt = recur(a, b, c - 1) + recur(a, b - 1, c - 1) - recur(a, b - 1, c)
    else:
        rt = recur(a - 1, b, c) + recur(a - 1, b - 1, c) + recur(a - 1, b, c - 1) - recur(a - 1, b - 1, c - 1)
    dp[a + 50][b + 50][c + 50] = rt
    return rt


dp = [[[False for i in range(101)] for j in range(101)] for k in range(101)]
while True:
    a, b, c = map(int, input().split())
    if a == b == c == -1:
        break
    print("w(", a, ", ", b, ", ", c, ") = ", recur(a, b, c), sep='')
