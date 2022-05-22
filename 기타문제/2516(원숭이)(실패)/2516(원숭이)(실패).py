N = int(input())
vs = []
for _ in range(N):
    larr = list(map(int, input().split()))
    if len(larr) == 1:
        vs.append([])
    else:
        vs.append(larr[1:])
a = []
b = []
check = [0] * N
for i in range(N):
    if len(vs[i]) == 0:
        if len(a) <= len(b):
            a.append(i + 1)
            check[i] = 1
        else:
            b.append(i + 1)
            check[i] = 2
    else:
        anum = 0
        bnum = 0
        for v in vs[i]:
            if check[v - 1] == 1:
                anum += 1
        for v in vs[i]:
            if check[v - 1] == 2:
                bnum += 1
        if anum <= bnum:
            a.append(i + 1)
            check[i] = 1
        else:
            b.append(i + 1)
            check[i] = 2
a.sort()
b.sort()

for tarr in a, b:
    print(len(tarr), end=' ')
    for v in tarr:
        print(v, end=' ')
    print()