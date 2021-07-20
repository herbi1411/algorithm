from sys import stdin
input = stdin.readline

N,M = map(int,input().split())
arr = list(map(int,input().split()))

start = 0
end = 2000000000
num = 0
while end >= start:
    num = 0
    mid = (end+start) // 2
    for a in arr:
        if mid < a:
            num += a - mid
    if num >= M:
        start = mid + 1
    else:
        end = mid - 1

print(end)