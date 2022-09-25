class deque:
    def __init__(self):
        self.lst = [0] * 1000
        self.size = 0
        self.sidx = 0
        self.eidx = 0
        self.capacity = 1000

    def append(self, val):
        if self.size == self.capacity:
            self.lst = self.lst.extend([0] * self.capacity)
            self.capacity *= 2
        self.lst[self.eidx] = val
        self.eidx = (self.eidx + 1) % self.capacity
        self.size += 1

    def popleft(self):
        if self.size == 0:
            return None
        rt = self.lst[self.sidx]
        self.sidx = (self.sidx + 1) % self.capacity
        self.size -= 1
        return rt

    def __len__(self):
        return self.size


T = int(input())

for t in range(1, T + 1):
    N = int(input())
    INF = 2147483647
    arr = [list(map(int, input().split())) for _ in range(N)]
    cost = [[INF] * N for _ in range(N)]
    q = deque()

    dx = [1, 0]
    dy = [0, 1]

    q.append((0, 0))
    cost[0][0] = arr[0][0]
    ans = INF

    while len(q) > 0:
        x, y = q.popleft()

        if (x, y) == (N - 1, N - 1):
            ans = min(ans, cost[x][y])
            continue

        for i in range(2):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < N and cost[x][y] + arr[nx][ny] < cost[nx][ny]:
                cost[nx][ny] = cost[x][y] + arr[nx][ny]
                q.append((nx, ny))

    print(f"#{t} {ans}")
