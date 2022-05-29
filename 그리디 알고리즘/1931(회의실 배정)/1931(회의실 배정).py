import sys

input = sys.stdin.readline

N = int(input())
arr = []
for _ in range(N):
    val = tuple(map(int, input().split()))
    arr.append(val)
arr.sort()
answer = 0
maxval = -1

for a, b in arr:
    if a >= maxval:
        answer += 1
        maxval = b
    elif maxval > b:
        maxval = b

print(answer)
