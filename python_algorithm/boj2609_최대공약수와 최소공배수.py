# 그림으로 이해하기 https://velog.io/@yerin4847/W1-%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C-%ED%98%B8%EC%A0%9C%EB%B2%95
# 최소공배수 벤다이어그램으로 이해하기 https://dimenchoi.tistory.com/46
import sys

arr = [int(n) for n in sys.stdin.readline().split()]

a, b = arr
divisor, dividened = min(arr), max(arr)

while dividened % divisor != 0:
    tmp = divisor
    divisor = dividened % divisor
    dividened = tmp

print(divisor, a*b // divisor)
