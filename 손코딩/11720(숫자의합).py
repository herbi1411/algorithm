
input()

sum = 0
num = int(input())
while num > 0:
    sum += num % 10
    num //= 10

print(sum)