from itertools import combinations

L, C = map(int, input().split())
cset = input().split()
cset.sort()
comb = combinations(cset, L)
answer = []

for indices in comb:
    m = 0
    j = 0
    for c in indices:
        if c in ['a', 'e', 'i', 'o', 'u']:
            m += 1
        else:
            j += 1
    if m < 1 or j < 2:
        continue
    answer.append(''.join(list(indices)))

for v in answer:
    print(v)