def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)

if __name__ == "__main__":
    n = int(input())
    print(fibonacci(n))

# DP안썼더니 시간초과남..😅