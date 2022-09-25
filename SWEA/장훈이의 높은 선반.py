T = int(input())

def dfs(depth, employee, st, visited, temp, N, B):
    global ans

    if depth == N or temp >= B:
        if temp >= B:
            ans = min(ans, temp - B)
        return

    for i in range(st, len(employee)):
        if not visited[i]:
            visited[i] = True
            dfs(depth + 1, employee, i + 1, visited, temp + employee[i], N, B)
            visited[i] = False

for t in range(1, T + 1):
    N, B = map(int, input().split())
    employee = list(map(int, input().split()))
    INF = 0x7fffffff
    ans = INF
    visited = [False] * N
    dfs(0, employee, 0, visited, 0, N, B)

    if ans == INF:
        print(f"#{t} -1")
    else:
        print(f"#{t} {ans}")