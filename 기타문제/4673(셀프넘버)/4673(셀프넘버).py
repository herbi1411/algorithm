selnum = [1 for _ in range(10001)]
selnum[0] = 0

for i in range(1,10001):
    nextnum = i + sum(list(map(int,str(i))))
    if nextnum <= 10000:
        selnum[nextnum] = 0

for i in range(len(selnum)):
    if selnum[i] == 1:
        print(i)

