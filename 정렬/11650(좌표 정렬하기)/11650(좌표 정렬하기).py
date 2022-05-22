import sys

input = sys.stdin.readline


def compare(a, b):
    if a[0] > b[0]:
        return 1
    elif a[0] == b[0]:
        if a[1] > b[1]:
            return 1
        else:
            return 0
    else:
        return 0


def mergeSort(points):
    if len(points) == 1:
        return points
    mid = len(points) // 2
    arr1 = mergeSort(points[0:mid])
    arr2 = mergeSort(points[mid:len(points)])
    index1 = 0
    index2 = 0
    rt = []
    while len(rt) < len(points):
        if index1 >= len(arr1):
            rt.append(arr2[index2])
            index2 += 1
        elif index2 >= len(arr2):
            rt.append(arr1[index1])
            index1 += 1
        else:
            if compare(arr1[index1], arr2[index2]) == 1:
                rt.append(arr2[index2])
                index2 += 1
            else:
                rt.append(arr1[index1])
                index1 += 1
    return rt


N = int(input())
points = []
for _ in range(N):
    points.append(tuple(map(int, input().split())))
points = mergeSort(points)
for x, y in points:
    print(x, y, sep=' ')
