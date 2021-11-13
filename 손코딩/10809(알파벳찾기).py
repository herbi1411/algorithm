s = input()

arr = [-1] * 26

for i,a in enumerate(s):
    if arr[ord(a)-ord('a')] == -1:
        arr[ord(a)-ord('a')] = i

for n in arr:
    print(n,end=" ")
print()

