import sys
#
# N = int(sys.stdin.readline())
# arr = []
# for _ in range(N):
#
#     n = sys.stdin.readline()
#     arr.append(int(n))


arr = sorted([7, 8, 10, 13, 19, 20, 23, 906, 303, 632, 1, 84])

target_num = 632

length = arr.__len__()

max_num = max(arr)
arr.remove(max_num)

print(arr)
