import sys

input = sys.stdin.readline


def DFS(x, y, matrix, visit, depth):
    global answer, R, C, dx, dy
    answer = max(answer, depth)

    for tx, ty in zip(dx, dy):
        nx = x + tx
        ny = y + ty
        if 0 <= nx < R and 0 <= ny < C and not visit[matrix[nx][ny]]:
            visit[matrix[nx][ny]] = True
            DFS(nx, ny, matrix, visit, depth + 1)
            visit[matrix[nx][ny]] = False


if __name__ == "__main__":
    R, C = map(int, input().split())
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    visit = [False] * 26
    answer = 0
    matrix = [list(map(lambda x : ord(x) - ord('A'), list(input().rstrip()))) for _ in range(R)]
    visit[matrix[0][0]] = True
    DFS(0, 0, matrix, visit, 1)
    print(answer)