def hanoi(N, start, end, sub):
    if N == 1:
        print(start, end)
    else:
        hanoi(N - 1, start, sub, end)
        print(start, end)
        hanoi(N - 1, sub, end, start) 

N = int(input())
print(2 ** N - 1)
if N <= 20:
    hanoi(N, 1, 3, 2)