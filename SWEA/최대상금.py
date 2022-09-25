T = int(input())

def dfs(depth, lst, C):
    global tset, aset

    if depth == C:
        aset.add(''.join(lst))
        return
    for i in range(len(lst) - 1):
        for j in range(i + 1, len(lst)):
            lst[i], lst[j] = lst[j], lst[i]
            if (''.join(lst), depth) not in tset:
                tset.add((''.join(lst), depth))
                dfs(depth + 1, lst, C)
            lst[i], lst[j] = lst[j], lst[i]

for t in range(1, T + 1):
    lst, C = input().split()
    lst, C = list(lst), int(C)

    aset = set()
    tset = set()
    dfs(0, lst, C)

    print(f"#{t} {max(aset)}")
