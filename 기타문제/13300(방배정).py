bucket1 = [0] * 6
bucket2 = [0] * 6

N, K = map(int, input().split())
for _ in range(N):
    a, b = map(int, input().split())
    if a == 0:
        bucket1[b - 1] += 1
    elif a == 1:
        bucket2[b - 1] += 1

ans = 0
for i in range(len(bucket1)):
    if bucket1[i] % K == 0:
        ans += bucket1[i] // K
    else:
        ans += bucket1[i] // K + 1
    if bucket2[i] % K == 0:
        ans += bucket2[i] // K
    else:
        ans += bucket2[i] // K + 1
print(ans)