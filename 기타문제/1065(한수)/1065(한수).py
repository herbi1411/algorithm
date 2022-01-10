n = int(input())
answer = 0

for i in range(1,n+1):
    nstr = str(i)
    strlen = len(nstr)
    flag = True
    interval = 0

    if strlen <= 2:
        answer+=1
        continue

    else:
        interval = ord(nstr[1]) - ord(nstr[0])
        for j in range(len(nstr)-1):
            if interval == ord(nstr[j+1]) - ord(nstr[j]):
                continue
            else:
                flag = False
                break

        if flag is True:
            answer += 1

print(answer)

