N, target = map(int,input().split())
arr = list(map(int, input().split()))
numArr = []
for i in arr:
    for k in range(len(numArr)):
        numArr.append(i + numArr[k])
    numArr.append(i)
print(numArr.count(target))