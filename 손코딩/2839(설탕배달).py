num = int(input())

n = num // 5
m = 0

while n >=0:
    if (num - 5*n) % 3 == 0:
        m = (num - 5*n) // 3
        break
    n -= 1

if n >=0:
    print(n+m)
else:
    print(-1)