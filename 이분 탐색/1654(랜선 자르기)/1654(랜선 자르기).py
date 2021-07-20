#틀림
from sys import stdin
import math
k,n = map(int,stdin.readline().split())
arr = [int(stdin.readline()) for _ in range(k)]
arr2 = [] #나머지
cm = min(arr)

while(1):
    temp = 0
    for a in arr:
        temp += a // cm
    if temp < n:
        cm //= 2
    elif temp > n:
        cm = math.ceil(cm * 1.5)
    else:
        for a in arr:
            arr2.append(a % cm)
        min_val = min(arr2)
        cm += min_val // 4
        break

print(cm)