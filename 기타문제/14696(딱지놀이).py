N = int(input())
for _ in range(N):
    lstA = list(map(int, input().split()))
    lstB = list(map(int, input().split()))

    lstA.pop(0)
    lstB.pop(0)

    bucketA = [0] * 4
    bucketB = [0] * 4

    for a in lstA:
        bucketA[4 - a] += 1
    for b in lstB:
        bucketB[4 - b] += 1

    result = "D"
    for a, b in zip(bucketA, bucketB):
        if a > b:
            result = "A"
            break
        elif a < b:
            result = "B"
            break
    print(result)