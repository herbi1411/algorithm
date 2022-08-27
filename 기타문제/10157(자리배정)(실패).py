C, R = map(int, input().split())
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
target = int(input())
temp = 1
x, y = R - 1, 0
flag = True
if target > C * R:
    flag = False
if flag:
    cnt = 0
    while temp + 2 * ((R - cnt) + (C - cnt)) - 4 < target:
        temp += 2 * ((R - cnt) + (C - cnt)) - 4
        cnt += 2
        x, y = x - 1, y + 1

    if temp == target:
        print(y + 1, R - x)
    for i in range(4):
        if i % 2 == 0:
            for _ in range(R - cnt - 1):
                x, y = x + dx[i], y + dy[i]
                temp += 1
                if temp == target:
                    print(y + 1, R - x)
        else:
            for _ in range(C - cnt - 1):
                x, y = x + dx[i], y + dy[i]
                temp += 1
                if temp == target:
                    print(y + 1, R - x)
else:
    print(0)