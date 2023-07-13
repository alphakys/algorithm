# 그림으로 이해하기 https://velog.io/@yerin4847/W1-%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C-%ED%98%B8%EC%A0%9C%EB%B2%95
import sys

n1, n2 = [int(n) for n in sys.stdin.readline().split()]

if n1 >= n2:
    divisor = n2
    dividend = n1
else:
    divisor = n1
    dividend = n2

while dividend % divisor != 0:
    tmp = divisor
    divisor = dividend % divisor
    dividend = tmp

print(divisor, (n1*n2) // divisor)
# 약수란 target 수를 나눠서 0이 나오는 수
# 그럼 나눠서 0이 떨어질 때까지 나눈다.


