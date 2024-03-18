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


def quick_sort(start, end):
    if start >= end:
        return

    l_pointer = start + 1
    r_pointer = end
    pivot = arr[start]

    while True:
        # If l_pointer num is larger than pivot
        # advance l_pointer to right direction
        while l_pointer <= r_pointer and pivot >= arr[l_pointer]:
            l_pointer += 1

        while l_pointer <= r_pointer and pivot <= arr[r_pointer]:
            r_pointer -= 1

        if l_pointer > r_pointer:
            arr[r_pointer], arr[start] = arr[start], arr[r_pointer]
            break

        arr[l_pointer], arr[r_pointer] = arr[r_pointer], arr[l_pointer]

    quick_sort(start, r_pointer - 1)
    quick_sort(r_pointer + 1, end)


quick_sort(0, len(arr) - 1)

output = io.StringIO()
for n in arr:
    output.write(f"{n}\n")

sys.stdout.write(output.getvalue())
# arr = [37, 94, 23, 19, 83, 75, 80, 16, 6, 81, 43, 75, 64, 15, 12, 86, 48, 12, 9, 99, 62, 61, 15, 87, 96, 66, 46, 59, 83, 90, 55, 48, 77, 67, 84, 79, 43, 11, 27, 92, 35, 49, 10, 40, 36, 99, 11, 13, 91, 5]
