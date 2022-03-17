N = int(input())
str_set = set()
sorted_arr = []

for _ in range(N):
    str_set.add(input())
sorted_arr = sorted(list(str_set), key=lambda x : (len(x),x))

for val in sorted_arr:
    print(val)