def DFS(x, y, matrix, aset, visit, depth):
    global answer, R, C
    answer = max(answer, depth)

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    for tx, ty in zip(dx, dy):
        nx = x + tx
        ny = y + ty
        if 0 <= nx < R and 0 <= ny < C and not visit[nx][ny] and matrix[nx][ny] not in aset:
            aset.add(matrix[nx][ny])
            visit[nx][ny] = True
            DFS(nx, ny, matrix, aset, visit, depth + 1)
            visit[nx][ny] = False
            aset.remove(matrix[nx][ny])


if __name__ == "__main__":
    R, C = map(int, input().split())
    answer = 0
    matrix = [list(input()) for _ in range(R)]
    aset = set()
    visit = [[False] * C for _ in range(R)]
    aset.add(matrix[0][0])
    visit[0][0] = True
    DFS(0, 0, matrix, aset, visit, 1)
    print(answer)