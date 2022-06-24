def getPrimeArr(num):
    primeArr = [True] * (num + 1)
    primeArr[0] = False
    primeArr[1] = False
    for i in range(2, num + 1):
        if primeArr[i]:
            temp = i + i
            while temp <= num:
                primeArr[temp] = False
                temp += i
    primeArr = [i for i in range(len(primeArr)) if primeArr[i]]
    return primeArr


def upperBound(s, e, target, arr):  # 작거나 같은
    if s > e:
        return e
    mid = (s + e) // 2
    if arr[mid] < target:
        return upperBound(mid + 1, e, target, arr)
    elif arr[mid] > target:
        return upperBound(s, mid - 1, target, arr)
    else:
        return mid



def lowerBound(s, e, target, arr):  # 큰
    if s > e:
        return s
    mid = (s + e) // 2
    if arr[mid] <= target:
        return lowerBound(mid + 1, e, target, arr)
    elif arr[mid] > target:
        return lowerBound(s, mid - 1, target, arr)

if __name__ == "__main__":
    primeArr = getPrimeArr(300000)
    while True:
        n = int(input())
        if n == 0:
            break
        lb = lowerBound(0, len(primeArr), n, primeArr)
        ub = upperBound(0, len(primeArr), n * 2, primeArr)
        print(ub - lb + 1)