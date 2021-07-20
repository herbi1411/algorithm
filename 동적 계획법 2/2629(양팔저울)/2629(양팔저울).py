import sys
input = sys.stdin.readline

s = int(input())
arr = list(map(int,input().split()))
c = int(input())
case = list(map(int,input().split()))
rs = []
hashmap = [0] * (sum(arr) + 1)
for i in range(s):
    for j in range(len(rs)):
        rs.append(rs[j]+arr[i])
        rs.append(abs(rs[j]-arr[i]))
    rs.append(arr[i])

for i in rs:
    hashmap[i] = 1;

for i in case:
    if hashmap[i] == 1:
        print("Y", end=" ")
    else:
        print("N", end=" ")