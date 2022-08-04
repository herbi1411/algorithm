from collections import deque

def BFS(key, ndict, vdict):
    q = deque() # 큐
    q.append(key)

    while len(q) > 0:
        v = q.popleft()
        for n in ndict[v]:
            if vdict[n] == False:
                vdict[n] = True
                q.append(n)


if __name__ == "__main__":
    idx = 1 # TC 번호
    while True:
        N = int(input())
        if N == 0:
            break

        ndict = {} # key:사람 // value:그 사람이 선행을 배푼 사람들 list
        ans = 0
        vdict = {} # 해당 사람을 방문했는지 key:사람 // value: True or False

        for _ in range(N):
            a, b = input().split()
            if a not in ndict:
                ndict[a] = []
            ndict[a].append(b)

        for key in ndict:
            vdict[key] = False # vdict 생성

        for key in ndict:
            if vdict[key] == True: # 이미 방문한 사람이면 패스
                continue
            vdict[key] = True
            ans += 1
            BFS(key, ndict, vdict) # BFS로 연결된 사람들 방문
        print(f"{idx} {ans}")
        idx += 1