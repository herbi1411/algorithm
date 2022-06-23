import sys

input = sys.stdin.readline

N = int(input())
parr = list(map(int, input().split()))
parr = [(i + 1, val) for i, val in enumerate(parr)]
parr.sort(key=lambda v: v[1] / v[0], reverse=True)

temp = N
answer = 0
for i, val in parr:
    quotient = temp // i
    answer += quotient * val
    temp -= i * quotient
    if temp == 0:
        break
print(answer)
