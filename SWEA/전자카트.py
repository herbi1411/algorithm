def dfs(depth, arr, N, temp, now):
    global ans

    if depth == N - 1:
        ans = min(ans, temp + arr[now][0])
        return

    for i in range(N):
        if not visited[i] and now != i:
            visited[i] = True
            dfs(depth + 1, arr , N, temp + arr[now][i], i)
            visited[i] = False


T = int(input())
for t in range(1, T + 1):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    visited = [False] * N
    ans = 2147483647
    visited[0] = True
    dfs(0, arr, N, 0, 0)
    print(f"#{t} {ans}")