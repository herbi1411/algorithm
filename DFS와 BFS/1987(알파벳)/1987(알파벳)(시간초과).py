def DFS(x, y, matrix, aset, depth):
    global answer, R, C
    answer = max(answer, depth)

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    for tx, ty in zip(dx, dy):
        nx = x + tx
        ny = y + ty
        if 0 <= nx < R and 0 <= ny < C and matrix[nx][ny] not in aset:
            aset.add(matrix[nx][ny])
            DFS(nx, ny, matrix, aset, depth + 1)
            aset.remove(matrix[nx][ny])


if __name__ == "__main__":
    R, C = map(int, input().split())
    answer = 0
    matrix = [list(input()) for _ in range(R)]
    aset = set()
    aset.add(matrix[0][0])
    DFS(0, 0, matrix, aset, 1)
    print(answer)