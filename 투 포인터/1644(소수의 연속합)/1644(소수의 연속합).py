def getPrimeNumList(maxNum):
    checkArr = [True] * (maxNum + 1)
    rt = []
    for i in range(2, maxNum + 1):
        if not checkArr:
            continue
        else:
            for j in range(i + i, maxNum + 1, i):
                checkArr[j] = False
    for i in range(2, maxNum + 1):
        if checkArr[i]:
            rt.append(i)
    return rt

N = int(input())
lst = getPrimeNumList(N)

cnt = 0
sp = 0
ep = 0
temp = 0

while sp < len(lst):
    if temp < N:
        if ep == len(lst):
            break
        temp += lst[ep]
        ep += 1
    elif temp >= N:
        if temp == N:
            cnt += 1
        temp -= lst[sp]
        sp += 1
print(cnt)