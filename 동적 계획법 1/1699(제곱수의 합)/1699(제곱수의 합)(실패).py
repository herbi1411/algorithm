from math import sqrt
N = int(input())
answer = 0
temp = N
for t in range(int(sqrt(N)),0,-1):
    while temp >= t**2:
        temp -= t**2
        answer += 1
    if temp == 0:
        break
print(answer)