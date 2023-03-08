'''

입력에 대하여 Kaprekar 연산을 통해 몇 단계 만에 6174가 되는지 한 줄에 하나씩 출력하시오.

'''

import sys

def Input_Data():
  num = int(sys.stdin.readline())
  return num

ans = -1
# 입력 받는 부분
num = Input_Data()

def bigAndSmall(one):
    #리스트로 변환
    one_list = list(map(int, str(one)))
    #오름차순으로 소팅한 것은 small로 저장 (int로 변환해서 저장)
    smallList = sorted(one_list)
    str_small = ''.join(map(str, smallList))
    #print("smallList str_small:", str_small)
    n_small = int(str_small)
    #내림차순으로 소팅한 것은 big으로 저장 (int로 변환해서 저장)
    bigList = sorted(one_list, reverse=True)
    str_big = ''.join(map(str, bigList))
    #print("bigList str_big:", str_big)
    n_big = int(str_big)
    return n_big, n_small

n = num
count = 0
while n!=6174:
    big, small = bigAndSmall(n)
    n = big - small
    #print("new n:", n)
    count = count + 1
ans = count    
# 출력하는 부분
print(ans)
