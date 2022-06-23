def getPrimeArr(maxNum):
    primeArr = [True] * (maxNum + 1)
    primeArr[0] = False
    primeArr[1] = False
    for i in range(2, maxNum + 1):
        if primeArr[i]:
            temp = i + i
            while temp <= maxNum:
                primeArr[temp] = False
                temp += i
    return primeArr


if __name__ == "__main__":
    T = int(input())
    primeArr = getPrimeArr(10000)
    for _ in range(T):
        n = int(input())
        smallPrime, bigPrime = 0, 0
        diff = 10000
        for i in range(2, n // 2 + 1):
            if primeArr[i] and primeArr[n - i] and n - i < diff:
                smallPrime = i
                bigPrime = n - i
                diff = n - i
        print(smallPrime, bigPrime)
