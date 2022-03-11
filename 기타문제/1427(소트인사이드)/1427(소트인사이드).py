num = input()
answer = ''

num = list(map(int,num))
num.sort(reverse= True)

for n in num:
    answer += str(n)

print(answer)