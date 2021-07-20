N = int(input())
k = []
num = []
arr = []
ans = []
sum_del = 0
for _ in range(N):
    k.append(int(input()))
    num.append(list(map(int,input().split())))

for i in range(N):
    num[i].sort()
    flag = True
    while len(num[i]) > 1:
        ans = []
        for j in range(0,len(num[i]) - 1,2):
            if flag:
                ans.append((num[i][j] + num[i][j + 1]));
            else:
                ans.append((num[i][j] + num[i][j+1]) * 2);
        if flag:
            flag = False
        if len(num[i]) % 2 == 1:
            ans.append(num[i][-1])
        num[i] = ans
    print(num[i][0])

print(k)
print(num)