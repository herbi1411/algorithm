m,n = map(int,input().split())

arr = [1] * 1000001

arr[0] = 0
arr[1] = 0

for i in range(2,1000001):
    if arr[i] == 1:
        t = 2
        while i * t <= 1000000:
            arr[i * t] = 0
            t += 1


for i in range(m,n+1):
    if arr[i] == 1:
        print(i)