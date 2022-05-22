from collections import deque

N, M = map(int, (input().split()))
matrix = [list(input()) for _ in range(N)]
arr = [[0] * (M - 2) for _ in range(N - 2)]
vdict = {'#': -1, 'O': 1}
cset = set()
answer = 0
R = (0, 0)
B = (0, 0)
for i in range(1, N - 1):
    for j in range(1, M - 1):
        if matrix[i][j] in vdict.keys():
            arr[i - 1][j - 1] = vdict[matrix[i][j]]
        elif matrix[i][j] == 'R':
            R = [i - 1, j - 1]
        elif matrix[i][j] == 'B':
            B = [i - 1, j - 1]

q = deque()
q.append((1, R, B))
cset.add((tuple(R), tuple(B)))
while len(q) > 0 and answer == 0:
    tnum, r, b = q.popleft()
    uldr = [(-1, 0), (0, -1), (1, 0), (0, 1)]  # up-left-down-right
    # left
    for i, t in enumerate(uldr):
        cflag = False  # continue flag
        sflag = False  # success flag
        tr, tb = r[:], b[:]
        while 0 <= tb[0] + t[0] < N - 2 and 0 <= tb[1] + t[1] < M - 2:
            if arr[tb[0] + t[0]][tb[1] + t[1]] == 1:
                cflag = True
                break
            elif arr[tb[0] + t[0]][tb[1] + t[1]] == -1:
                break
            else:
                tb[0] += t[0]
                tb[1] += t[1]
        while 0 <= tr[0] + t[0] < N - 2 and 0 <= tr[1] + t[1] < M - 2 and not cflag:
            if arr[tr[0] + t[0]][tr[1] + t[1]] == 1:
                sflag = True
                break
            elif arr[tr[0] + t[0]][tr[1] + t[1]] == -1:
                break
            else:
                tr[0] += t[0]
                tr[1] += t[1]
        if not cflag:
            if sflag:
                answer = tnum
                break
            elif tr[0] == tb[0] and tr[1] == tb[1]:
                if i == 0:  # u
                    if r[0] > b[0]:
                        tr[0] = tr[0] + 1
                    else:
                        tb[0] += 1
                elif i == 1:  # l
                    if r[1] > b[1]:
                        tr[1] += 1
                    else:
                        tb[1] += 1
                elif i == 2:  # d
                    if r[0] < b[0]:
                        tr[0] -= 1
                    else:
                        tb[0] -= 1
                elif i == 3:  # r
                    if r[1] < b[1]:
                        tr[1] -= 1
                    else:
                        tb[1] -= 1
            if tnum < 10:
                if (tuple(tr), tuple(tb)) not in cset:
                    q.append((tnum + 1, tr, tb))
                    cset.add((tuple(tr), tuple(tb)))
if answer == 0:
    print(-1)
else:
    print(answer)