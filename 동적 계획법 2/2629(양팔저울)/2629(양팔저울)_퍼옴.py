import sys

input = sys.stdin.readline


def cal(cnum, weight):
    if cnum > N:
        return
    elif dp[cnum][weight] != -1:
        return
    else:
        dp[cnum][weight] = 1
        cal(cnum + 1, weight + arr[cnum])
        cal(cnum + 1, weight)
        cal(cnum + 1, abs(weight - arr[cnum]))


N = int(input())
arr = list(map(int, input().split()))
arr.append(-1)
M = int(input())
case = list(map(int, input().split()))
dp = [[-1] * (500 * N + 1) for _ in range(N+1)]
cal(0, 0)

for i in case:
    if dp[N-1][i] == 1:
        print("Y", end=" ")
    else:
        print("N", end=" ")
