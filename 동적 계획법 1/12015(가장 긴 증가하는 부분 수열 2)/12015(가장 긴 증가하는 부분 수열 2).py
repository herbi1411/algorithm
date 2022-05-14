import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
answer = []
for val in arr:
    if len(answer) == 0:
        answer.append(val)
    else:
        if answer[-1] < val:
            answer.append(val)
        elif answer[-1] > val:
            s = 0
            e = len(answer) - 1
            while s <= e:
                mid = (s + e) // 2
                if answer[mid] == val:
                    e = mid
                    break
                elif answer[mid] > val:
                    e = mid - 1
                elif answer[mid] < val:
                    s = mid + 1
            if answer[e] == val:
                continue
            else:
                answer[e + 1] = val

print(len(answer))
