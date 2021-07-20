#실패(시간초과)
def nest(index,i,arr):
    ret = 1
    i = 1
    while 1:
        if index - i >= 0 and arr[index - i] == arr[index]:
            ret +=1
            i += 1
        else:
            break
    i = 1
    while 1:
        if index + i < len(arr) and arr[index + i] == arr[index]:
            ret += 1
            i += 1
        else:
            break
    return ret
def findNum(start,end,arr,i):
    if end-start < 0:
        return 0
    index = (start + end) // 2
    if arr[index] > i:
        return findNum(start,index-1,arr,i)
    elif arr[index] < i:
        return findNum(index+1,end,arr,i)
    elif arr[index] == i:
        return nest(index,i,arr)


num1 = int(input())
arr = list(map(int, input().split()))
arr.sort()
num2 = int(input())
arr2 = list(map(int, input().split()))
for i in arr2:
    print(findNum(0,len(arr) - 1, arr,i),end=" ")