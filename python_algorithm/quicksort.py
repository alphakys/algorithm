import io
import sys
import os

sys.setrecursionlimit(100000)
# Size of the file in bytes, if it is a regular file or a symbolic link.
# inputs = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
n = int(sys.stdin.readline().rstrip())

arr = [0] * n

for _ in range(n):
    arr[_] = int(sys.stdin.readline().rstrip())
#      0  1   2   3   4   5  6   7  8  9
# arr = [37, 94, 23, 19, 83, 75, 80, 16, 6, 81, 43, 75, 64, 15, 12, 86, 48, 12, 9, 99, 62, 61, 15, 87, 96, 66, 46, 59, 83, 90, 55, 48, 77, 67, 84, 79, 43, 11, 27, 92, 35, 49, 10, 40, 36, 99, 11, 13, 91, 5]

# arr = [37, 94, 23, 19, 83, 75, 80]
# two pointer 전략

# print("check : ", start, l_pointer, r_pointer, end)

def quick_sort(start, end):
    # l pointer가 end 보다 크거나 같으면 왜냐면 start는 pivot이기 때문에 l_pointer의 index를 비교하자.
    if start >= end:
        return
    l_pointer = start + 1
    r_pointer = end
    pivot = arr[start]

    # print(l_pointer, r_pointer)
    while True:

        # l_pointer가 pivot 보다 작으면 advance ->
        while l_pointer <= r_pointer and arr[l_pointer] <= pivot:
            l_pointer += 1

        # r_pointer가 pivot 보다 크면 advance <-
        while l_pointer <= r_pointer and arr[r_pointer] >= pivot:
            r_pointer -= 1

        #print(f"l_pointer : {l_pointer}, r_pointer : {r_pointer}")
        if l_pointer > r_pointer:
            arr[r_pointer], arr[start] = arr[start], arr[r_pointer]
            # print("break")
            # print(arr)
            # print()
            break

        # print("swap")
        arr[l_pointer], arr[r_pointer] = arr[r_pointer], arr[l_pointer]
        # print(arr)
    # print(arr)
    # print("check : ", start, l_pointer, r_pointer, end)
    quick_sort(start, r_pointer - 1)
    quick_sort(r_pointer + 1, end)
    return

quick_sort(0, len(arr)-1)

output = io.StringIO()
for n in arr:
    output.write(f"{n}\n")

sys.stdout.write(output.getvalue())
