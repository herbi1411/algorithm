N = int(input())
arr = [1] * 10
arr[0] = 0
arr2 = [0] * 10
DIV_NUM = 1000000000
for i in range(1, N):
    if i % 2 == 1:
        temp = arr2
        origin = arr
    else:
        temp = arr
        origin = arr2
    for j in range(1, 9):
        temp[j] = (origin[j - 1] + origin[j + 1]) % DIV_NUM
    temp[0] = (origin[1]) % DIV_NUM
    temp[9] = (origin[8]) % DIV_NUM
if N % 2 == 1:
    print(sum(arr) % DIV_NUM)
else:
    print(sum(arr2) % DIV_NUM)