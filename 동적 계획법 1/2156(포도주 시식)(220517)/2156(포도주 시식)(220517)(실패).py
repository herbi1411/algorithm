import sys

input = sys.stdin.readline

N = int(input())
arr = [int(input()) for _ in range(N)]
c1 = [0] * N
c2 = [0] * N
for i in range(N):
    if i == 0:
        c1[i], c2[i] = arr[i], 0
    elif i == 1:
        c1[i], c2[i] = arr[i], arr[0] + arr[i]
    else:
        c1[i], c2[i] = max(c1[i - 2], c2[i - 2]) + arr[i], c1[i - 1] + arr[i]
print(c1, c2, sep='\n')
print(max(max(c1), max(c2)))
