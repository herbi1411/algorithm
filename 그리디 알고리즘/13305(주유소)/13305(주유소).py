import sys

input = sys.stdin.readline

N = int(input())
distArr = list(map(int, input().split()))
gasCostArr = list(map(int, input().split()))[:-1]
minGasCost = 10 ** 9 + 1
answer = 0

for dist, gasCost in zip(distArr, gasCostArr):
    minGasCost = min(minGasCost, gasCost)
    answer += minGasCost * dist
print(answer)