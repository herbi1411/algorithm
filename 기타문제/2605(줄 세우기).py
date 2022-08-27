N = int(input())
arr = list(map(int, input().split()))
lst = []
for k in range(N):
    lst.insert(len(lst) - arr[k], k + 1)
print(*lst)