from collections import deque  # BFS를 위한 Queue
from itertools import combinations  # 조합을 구하기 위한 combinations
import copy  # 배열의 깊은 복사를 위한 copy

N, M = map(int, input().split())  # 직사각형의 가로, 세로
matrix = [list(map(int, input().split())) for _ in range(N)]  # 2차원 좌표
virus = []  # 바이러스의 좌표를 담을 배열
hole = []  # 빈칸을 담을 배열
answer = 0
dx = [-1, 1, 0, 0]  # 바이러스의 x위치 변화 (상,하,좌,우)
dy = [0, 0, -1, 1]  # 바이러스의 y위치 변화 (상,하,좌,우)

for i in range(N):
    for j in range(M):  # 모든 점에 대해
        if matrix[i][j] == 2:  # 값이 바이러스면
            virus.append((i, j))  # 바이러스 배열에 추가
        elif matrix[i][j] == 0:  # 값이 빈칸이면
            hole.append((i, j))  # 빈칸에 추가

hole_comb = combinations(hole, 3)  # 빈칸 좌표 중 3개를 고르는 경우의 수 담기
for indices in hole_comb:  # 각 경우마다
    # dupMatrix = matrix[:] # 깊은 복사 아님
    dupMatrix = copy.deepcopy(matrix)  # 좌표 배열을 복사
    temp = 0  # 그래프 탐색후 빈칸의 갯수를 담을 변수
    q = deque()  # 큐
    for x, y in indices:  # 각 선택된 점마다
        dupMatrix[x][y] = 1  # 값을 0 -> 1로 바꾸기
    for x, y in virus:  # 각 바이러스마다
        q.append((x, y))  # 큐에 바이러스 위치 삽입(초기값)
    ###BFS###
    while len(q) > 0:
        x, y = q.popleft()
        for tx, ty in zip(dx, dy):  # 현재 점에서 (상,하,좌,우)의 좌표 변화량
            nx = x + tx  # 다음 x좌표
            ny = y + ty  # 다음 y좌표
            if 0 <= nx < N and 0 <= ny < M and dupMatrix[nx][ny] == 0:  # 다음 좌표값이 직사각형 안에 있고, 값이 0이라면(빈칸이라면)
                dupMatrix[nx][ny] = 2  # 값을 바이러스(2)로 바꾸고
                q.append((nx, ny))  # 큐에 좌표 삽입
    for i in range(N):
        for j in range(M):
            if dupMatrix[i][j] == 0:  # 모든 점에대해 값이 0인 점의 갯수 세기
                temp += 1
    answer = max(answer, temp)  # 정답으로 각 경우마다 최대값 갱신
print(answer)