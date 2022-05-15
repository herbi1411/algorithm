N = int(input())
arr = [N] * (N + 1)
arr[N] = 0

for i in range(N, 1, -1):
    if arr[i - 1] > arr[i]:
        arr[i - 1] = arr[i] + 1
    if i % 3 == 0 and arr[i // 3] > arr[i]:
        arr[i // 3] = arr[i] + 1
    if i % 2 == 0 and arr[i // 2] > arr[i]:
        arr[i // 2] = arr[i] + 1
print(arr[1])
