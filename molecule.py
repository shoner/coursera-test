'''
Welcome to GDB Online.
GDB online is an online compiler and debugger tool 

'''
import sys

def Input_Data():
    readl = sys.stdin.readline
    N = int(readl())
    return N

ans = []
# 입력 받는 부분
N = Input_Data()

# 여기서부터 작성
def Solve():
    alist = [(0,0,1)] # (분수값, 분자, 분모)
    for i in range(2, N+1):
        for j in range(1, i): #분자가 0인 것은 이미 저장되어 있으므로 중복 뺌
            alist.append((j/i, j, i))
    alist.append((1,1,1)) # 1도 추가 
     #sort ascending: 분수값 오름차순 정렬
    alist.sort()
    #중복되는 분수값이 제거된 최종 리스트 만들기, 출력 형식에 맞게 저장
    ans = ["0/1"]
    for i in range(1, len(alist)):
        if alist[i-1][0] != alist[i][0]:
            ans.append("{}/{}".format(alist[i][1], alist[i][2])) #i인덱스로 꺼낸 분자, 분모를 분자/분모 포맷에 맞춰 ans 리스트에 저장
    return ans

ans = Solve()
# 출력하는 부분
print(*ans, sep='\n')
