

def mergeSort(arr):
    if len(arr) == 1:
        return arr

    mid = len(arr) // 2
    rtarr = []
    arr1 = mergeSort(arr[:mid])
    arr2 = mergeSort(arr[mid:])

    arr1Size = len(arr1)
    arr2Size = len(arr2)
    arr1Index = 0
    arr2Index = 0

    counter = 0
    while counter < len(arr):
        if arr1Index == arr1Size:
            rtarr.append(arr2[arr2Index])
            arr2Index += 1
        elif arr2Index == arr2Size:
            rtarr.append(arr1[arr1Index])
            arr1Index += 1
        else:
            if arr1[arr1Index] >= arr2[arr2Index]:
                rtarr.append(arr2[arr2Index])
                arr2Index += 1
            else:
                rtarr.append(arr1[arr1Index])
                arr1Index += 1
        counter += 1
    return rtarr




n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))

arr = mergeSort(arr)

for v in arr:
    print(v)

