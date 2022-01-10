n = int(input())
answer = 0

for _ in range(n):
    word = input()
    flag = True
    check = [0 for a in range(26)]
    now = word[0]
    check[ord(word[0]) - ord('a')] = 1

    for i in range(1,len(word)):
        if now == word[i]:
            continue
        else:
            if check[ord(word[i]) - ord('a')] == 1:
                flag = False
                break
            else:
                check[ord(word[i]) - ord('a')] = 1
                now = word[i]

    if flag:
        answer+=1

print(answer)