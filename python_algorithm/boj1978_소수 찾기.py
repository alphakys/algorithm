import sys
import math
N = int(sys.stdin.readline())

example = [int(n) for n in sys.stdin.readline().split()]

arr = [1]
for i in range(2, 1000):
    j = 2
    sq = int(math.sqrt(i))
    is_prime = True
    for _ in range(2, sq+1):
        if i % _ == 0:
            # 약수가 있음 즉 소수가 아님
            is_prime = False

    if is_prime:
        while i * j <= 1000:
            # print(i*j)
            arr.append(i*j)
            j += 1
# print(arr)
for e in example:
    if arr.__contains__(e):
        N -= 1

print(N)