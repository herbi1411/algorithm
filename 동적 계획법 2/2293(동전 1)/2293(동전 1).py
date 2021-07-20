import sys
input = sys.stdin.readline


def solve(idx, f):
    check = sum([idx[k] * arr[k] for k in range(len(arr))])
    if check == 10:
        global rt
        rt += 1
        # print(idx)
    elif check > K:
        return
    else:
        for i in range(f, len(arr)):
            index2 = idx[:]
            index2[i] += 1
            solve(index2, i)


N, K = map(int, input().split())
arr = [int(input()) for _ in range(N)]
index = [0] * len(arr)
rt = 0
solve(index, 0)
print(rt)
# print(N,K)
# print(arr)
