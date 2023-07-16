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


# array([22, 41,  6, 16,  9,  1,  5]),
# array([21,  9, 31, 11,  3,  4, 21]),
# array([12, 13, 21,  1, 13, 31,  9]),
# array([14, 27, 10,  9, 32,  2,  6]),
# array([ 4, 27,  1, 10,  7,  2, 49]),
# array([33,  2,  8,  3,  6,  5, 43]),
# array([ 2,  1,  8, 35,  5, 11, 38]),
# array([ 7,  6,  8, 10,  5, 60,  4]),
# array([20,  2,  8,  1, 17,  4, 48])]
