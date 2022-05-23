import sys

input = sys.stdin.readline
N, M = map(int, input().split())

pdict = {}
parr = []
for i in range(N):
    s = input().rstrip()
    pdict[s] = i + 1
    parr.append(s)
for j in range(M):
    s = input().rstrip()
    if s.isnumeric():
        print(parr[int(s) - 1])
    else:
        print(pdict[s])