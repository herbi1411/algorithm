import sys

input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(map(int, input().split()))
prefix = [0] * N
num = 0
for i in range(N):
    num += arr[i]
    prefix[i] = num

for _ in range(M):
    a, b = map(int, input().split())
    print(prefix[b - 1] - prefix[a - 1] + arr[a - 1])
