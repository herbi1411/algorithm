T = int(input())
for _ in range(T):
    x, y = map(int, input().split())
    dist = y - x
    answer = 0
    temp = 0
    count = 0
    addNum = 1
    while temp < dist:
        temp += addNum
        count += 1
        if count % 2 == 0:
            addNum += 1
        answer += 1
    print(answer)