N = int(input())

for _ in range(N):
    a, b = map(int, input().split())
    bigNum = 1
    smallNum = 1
    while a >= 1:
        bigNum *= b
        smallNum *= a
        b -= 1
        a -= 1
    print(bigNum // smallNum)