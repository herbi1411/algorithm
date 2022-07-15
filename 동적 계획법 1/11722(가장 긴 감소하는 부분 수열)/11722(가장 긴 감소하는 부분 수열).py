def lowerbound(s, e, arr, t):
    if s > e:
        return e
    mid = (s + e) // 2
    if arr[mid] > t:
        return lowerbound(s, mid - 1, arr, t)
    else:
        return lowerbound(mid + 1, e, arr, t)

N = int(input())
arr = list(map(int, input().split()))
ans = []
for v in arr:
    if len(ans) == 0:
        ans.append(v)
    elif v < ans[0]:
        ans.insert(0, v)
    else:
        lbIdx = lowerbound(0, len(ans) - 1, ans, v)
        ans[lbIdx] = v
print(len(ans))