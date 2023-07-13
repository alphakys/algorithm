import sys

sys.stdin.readline()
arr = sys.stdin.readline().split()

arr = {k: k for k in arr}

sys.stdin.readline()
target_arr = sys.stdin.readline().split()

answer = '\n'.join('1' if arr.get(n) else '0' for n in target_arr)

sys.stdout.write(answer)

# for target in target_arr:
#     left = 0
#
#     right = N - 1
#     mid = (right - left) // 2 + left
#
#     answer = 0
#
#     while left <= right:
#         if arr[mid] < target:
#             left = mid + 1
#         elif arr[mid] > target:
#             right = mid - 1
#         else:
#             sys.stdout.write('1\n')
#             answer = 1
#             break
#
#         if left == mid or right == mid:
#             break
#         mid = (right - left) // 2 + left
#
#     if not answer:
#         sys.stdout.write('0\n')
