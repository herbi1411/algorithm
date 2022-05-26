def nQueen(row, N, matrix):
    global answer  # 정답값을 Update하기 위해 Global변수임을 명시
    if row == N:  # 현재위치가 N이면 (체스판에 N개의 Queen을 모두 놓았다면)
        answer += 1  # 정답 + 1
        return
    else:
        check = [0] * N  # 현재 행에 놓을 수 있는 Queen의 위치를 저장하기 위한 배열 (값이 0이면 놓을 수 있고, 1이면 놓을 수 없다.)
        for i in range(row):  # 현재 행의 앞의 행들에 대해서
            check[matrix[i]] = 1  # 같은 열에 있는 위치에는 놓을 수 없다
            if 0 <= row - i + matrix[i] < N:  # 위쪽 행들의 각 Queen에서 오른쪽 아래 대각선 방향으로 내려왔을 때 현재 행에서의 위치가 체스판 안에 있다면
                check[row - i + matrix[i]] = 1  # 해당 위치에는 Queen을 놓을 수 없다.
            if 0 <= matrix[i] - row + i < N:  # 위쪽 행들의 각 Queen에서 왼쪽 아래 대각선 방향으로 내려왔을 때 현재 행에서의 위치가 체스판 안에 있다면
                check[matrix[i] - row + i] = 1  # 해당 위치에는 Queen을 놓을 수 없다.
        for i, temp in enumerate(check):  # check의 index와 value를 가져와
            if temp == 0:  # 값이 0이면(행에서 index위치에 Queen을 놓을 수 있다면)
                matrix[row] = i # 해당 위치에 Queen을 놓고
                nQueen(row + 1, N, matrix) # 다음 행으로 이동


N = int(input())
answer = 0  # 정답 값
matrix = [0] * N  # N 크기의 1차원 배열을 생성 index: 행의 값 value: 해당 행에서의 Queen 위치
nQueen(0, N, matrix)  # 0행부터 Queen을 채우기
print(answer)
