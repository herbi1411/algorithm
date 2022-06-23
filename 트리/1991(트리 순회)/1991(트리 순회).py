def preorder(now, pdict):
    if now == '.':
        return
    print(now, end='')
    preorder(pdict[now][0], pdict)
    preorder(pdict[now][1], pdict)

def inorder(now, pdict):
    if now == '.':
        return
    inorder(pdict[now][0], pdict)
    print(now, end='')
    inorder(pdict[now][1], pdict)


def postorder(now, pdict):
    if now == '.':
        return
    postorder(pdict[now][0], pdict)
    postorder(pdict[now][1], pdict)
    print(now, end='')


if __name__ == "__main__":
    N = int(input())
    pdict = dict()
    for _ in range(N):
        parent, left, right = input().split()
        pdict[parent] = [left, right]

    preorder('A', pdict)
    print("")
    inorder('A', pdict)
    print("")
    postorder('A', pdict)
    print("")