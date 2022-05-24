from math import *


def distance(x1, y1, x2, y2):
    return pow(x1 - x2, 2) + pow(y1 - y2, 2)


N = int(input())
for _ in range(N):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    dt = distance(x1, y1, x2, y2)
    if x1 == x2 and y1 == y2:
        if r1 == r2:
            print(-1)
        else:
            print(0)
    elif dt == pow(r1 + r2, 2) or dt == pow(r1 - r2, 2):
        print(1)
    elif dt > pow(r1 + r2, 2):
        print(0)
    elif dt < pow(r1 + r2, 2):
        print(2)