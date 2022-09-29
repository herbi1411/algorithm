# 크루스칼 알고리즘

def getHead(t, arr):
    temp = t
    while arr[temp] != temp:
        temp = arr[temp]
    return temp


def union(a, b, arr):
    target = getHead(b, arr)

    temp = a
    while arr[temp] != temp:
        nhead = arr[temp]
        arr[temp] = target
        temp = nhead
    arr[temp] = target


T = int(input())
for t in range(1, T + 1):
    V, E = map(int, input().split())
    V += 1
    ans = 0
    cnt = 0
    edge = []
    arr = [i for i in range(V)]
    for _ in range(E):
        n1, n2, w = map(int, input().split())
        edge.append((n1, n2, w))

    edge.sort(key=lambda x: (x[2], x[0], x[1]))

    for n1, n2, w in edge:
        if getHead(n1, arr) != getHead(n2, arr):
            ans += w
            union(n1, n2, arr)
            cnt += 1
        if cnt == V - 1:
            break

    print(f"#{t} {ans}")
