def nQueen(row, N, matrix):
    global answer
    if row == N:
        answer += 1
        return
    else:
        for temp in range(N):
            flag = True
            for i in range(row):
                if matrix[i] == temp or temp - matrix[i] == row - i or matrix[i] - temp == row - i:
                    flag = False
                    break
            if flag:
                matrix[row] = temp
                nQueen(row + 1, N, matrix)


N = int(input())
answer = 0
matrix = [0] * N
nQueen(0, N, matrix)
print(answer)
