N, M = map(int, input().split())
if N <= 2:
    print(N)
elif N > M:
    print(M * 2 - 1)
else:
    print((N - 1) * 2)