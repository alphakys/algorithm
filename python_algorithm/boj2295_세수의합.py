import random
import sys

# N = int(sys.stdin.readline())
# arr = []
# for _ in range(N):
#
#     n = sys.stdin.readline()
#     arr.append(int(n))

def binary_search(target_num, length, arr):
    left = 0
    right = length
    mid = (right - left) // 2 + left

    answer = None
    # i = 0
    while left <= right:
        if arr[mid] < target_num:
            left = mid + 1
        elif arr[mid] > target_num:
            right = mid - 1
        else:
            answer = arr[mid]
            break
        mid = (right - left) // 2 + left
    return answer

import numpy as np
arr = np.random.randint(1, 1000, 10)
# print(arr)

# arr = [7, 8, 10, 13, 19, 20, 23, 906, 303, 632, 1, 84]
# arr = [7, 8, 10, 13, 19, 20, 23, 906, 303, 550, 1, 84]
sorted_arr = sorted(arr)

target_num = max(sorted_arr)
sorted_arr.remove(target_num)
length = sorted_arr.__len__()

print(arr)
for i in range(length - 1, -1, -1):
    print(sorted_arr)
    sum_ = sorted_arr[i]

    for j in range(i - 1, -1, -1):
        search_num = target_num - (sum_ + sorted_arr[j])

        print(f'{target_num}, {sum_}, {sorted_arr[j]}, search_num : {search_num}')
        search_num = binary_search(search_num, j, sorted_arr)
        if search_num:
            # print(f'{arr.index(search_num)} {arr.index(sum_)}  {arr.index(sorted_arr[j])}')
            # print("정답 | ", target_num)
            sys.stdout.write(f'{target_num}')

    target_num = max(sorted_arr)
    sorted_arr.remove(target_num)
    length = sorted_arr.__len__()

    if length == 3:
        break
