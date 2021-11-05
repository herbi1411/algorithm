import sys
input = sys.stdin.readline

def findNum(num):
    answer = 0
    acumulnum = 0
    div2 = 1 #num보다 작은 2의 n승의 최댓값
    while pow(2,div2+1) <= num:
        div2+=1

    while(div2 >= 0):
        quotient = num // pow(2,div2)
        answer += (quotient - acumulnum) * pow(2,div2)
        acumulnum = quotient
        # print("나누기: ",pow(2,div2)," 몫: ",quotient, "누적합: ", acumulnum, "정답: ",answer)
        div2 -= 1
    return answer

A,B = map(int,input().split())
a = findNum(A-1)
b = findNum(B)
# print(a,b)
print(b-a)




