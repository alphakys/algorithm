import sys

# arr = [int(n) for n in sys.stdin.readlines()]
# sys.stdin.close()

import numpy as np
arr = [21,  9, 31, 11,  3,  4, 21] + [2, 10]

target_num = sum(arr) - 100

for idx, i in enumerate(arr):
    if i >= target_num or idx + 1 > 8:
        continue

    for j in arr[idx+1:]:
        if i + j == target_num:
            arr.remove(i)
            arr.remove(j)

            sys.stdout.write('\n'.join([str(n) for n in sorted(arr)]))
            exit()
