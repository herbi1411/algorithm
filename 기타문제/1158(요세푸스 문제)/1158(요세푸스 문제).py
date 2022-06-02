from collections import deque

N, K = map(int, input().split())
q = deque()
answer = deque()
for num in range(1, N + 1):
    q.append(num)
while len(q) > 0:
    for _ in range(K - 1):
        q.append(q.popleft())
    answer.append(q.popleft())

print("<", answer.popleft(), end="", sep='')
while len(answer) > 0:
    print(",", answer.popleft(), end="",)
print(">")