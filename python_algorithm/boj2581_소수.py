import sys
import math
import numpy as np

# M = int(sys.stdin.readline())
# N = int(sys.stdin.readline())


nums = np.arange(1, 10001)

arr = [1]
for i in range(2, 101):
    sq = int(math.sqrt(i))

    is_prime = True
    for j in range(2, sq+1):
        if i % j == 0:
            is_prime = False

    if is_prime:
        for k in range(2, 105):
            arr.append(i*k)

print(np.array(arr).equal(nums))

print(max(arr))