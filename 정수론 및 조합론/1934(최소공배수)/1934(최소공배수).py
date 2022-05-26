def gcd(a, b):
    if a < b:
        return gcd(b, a)
    elif b == 0:
        return a
    return gcd(b, a % b)


N = int(input())

for _ in range(N):
    a, b = map(int, input().split())
    gcdNum = gcd(a,b);
    lcm = gcdNum * a // gcdNum * b // gcdNum
    print(lcm)