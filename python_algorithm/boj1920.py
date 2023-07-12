import sys

# N = int(sys.stdin.readline())

import numpy as np
arr = list(set(np.random.randint(1, 10000, 100000)))
answer = arr[:2000]
answer += list(set(np.random.randint(1, 10000, 5000)))

# arr = sorted([int(n) for n in sys.stdin.readline().split()])
arr = sorted(arr)

# length = int(sys.stdin.readline())

# target_arr = [int(n) for n in sys.stdin.readline().split()]

print(arr.__len__(), answer.__len__())



target_arr = answer

for target in target_arr:
    left = 0
    right = target_arr.__len__() - 1
    mid = (right - left) // 2 + left

    answer = 0
    try:
        while left <= right:
            if arr[mid] < target:
                left = mid + 1
            elif arr[mid] > target:
                right = mid - 1
            else:
                sys.stdout.write('1\n')
                answer = 1
                break

            mid = (right - left) // 2 + left
    except Exception as e:
        print(e)
        print(f'len of arr : {arr.__len__()}')
        print(f'mid : {mid}, target : {target}')
    if not answer:
        sys.stdout.write('0\n')
