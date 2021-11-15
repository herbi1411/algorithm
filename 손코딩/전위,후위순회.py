
def preorder(preo,path,visit,now):
    if visit[now] == 1:
        return
    preo.append(now)
    visit[now] = 1

    for i in range(len(path[now])):
        preorder(preo,path,visit,path[now][i])

def postorder(posto,path,visit,now):
    if visit[now] == 1:
        return
    visit[now] = 1

    for i in range(len(path[now])):
        postorder(posto,path,visit,path[now][i])
    posto.append(now)

v,e = map(int,input().split())
path = [[] for i in range(v+1)]
preo = []
posto = []
ino = []
for i in range(e):
    a,b = map(int,input().split())
    path[a].append(b)
    path[b].append(a)

visit = [0] * (v+1)
preorder(preo,path,visit,1)
print("preorder: ",preo)

visit = [0] * (v+1)
postorder(posto,path,visit,1)
print("postorder: ",posto)

# visit = [0] * (v+1)
# inorder(ino,path,visit,1)
# print("inorder: ",ino)


print(path)












'''
8 7 
1 2
2 4
2 5
5 6
1 3
3 7
3 8


v: 8 e: 7
'''