N = int(input())

dp = [[0] * 10 for _ in range(N)]  # 길이 1~N에 대해 끝 자리가 0~9인 오르막 수의 개수를 담을 2차원 배열
for i in range(10):  # 1자리 오르막수 개수 초기화
    dp[0][i] = 1
for i in range(1, N):  # 길이가 N까지 가면서
    temp = 0  # 이전길이에서 끝자리가 0~j인 오르막 수의 개수를 저장할 변수
    for j in range(10):
        temp += dp[i - 1][j]  # 이전길이 dp배열에서 현재 끝자리 값을 더하기
        temp %= 10007
        dp[i][j] = temp  # dp값 저장
print(sum(dp[N - 1]) % 10007)  # 정답값은 길이 N인 0~9까지 오르막 수의 합 % 10007
