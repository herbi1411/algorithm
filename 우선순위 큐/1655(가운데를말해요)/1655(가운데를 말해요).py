import sys
import heapq

input = sys.stdin.readline

N = int(input())

minpq = []
maxpq = []

for i in range(N):
    num = int(input())
    if len(minpq) == len(maxpq):
        if len(minpq) > 0 and minpq[0] < num:
            heapq.heappush(minpq, num)
            num = heapq.heappop(minpq)
        heapq.heappush(maxpq, -num)
    elif len(minpq) < len(maxpq):
        temp = -heapq.heappop(maxpq)
        if num <= temp:
            heapq.heappush(maxpq, -num)
            heapq.heappush(minpq, temp)
        else:
            heapq.heappush(minpq, num)
            heapq.heappush(maxpq, -temp)

    print(-maxpq[0])
