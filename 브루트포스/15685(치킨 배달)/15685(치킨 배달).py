from itertools import combinations

N, M = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(N)]
chicken = []
house = []
answer = 987654231
for i in range(N):
    for j in range(N):
        if matrix[i][j] == 2:
            chicken.append((i, j))
        elif matrix[i][j] == 1:
            house.append((i, j))
for comb in combinations(chicken, M):
    temp = 0
    for x, y in house:
        cd = 987654321
        for cx, cy in comb:
            cd = min(cd, abs(x - cx) + abs(y - cy))
        temp += cd
    answer = min(answer, temp)
print(answer)