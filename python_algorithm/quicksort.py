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


def quick_sorting(start, limit):
    if start + 1 >= limit:
        return
    pivot = arr[start]
    l_pointer = start + 1
    r_pointer = limit - 1

    while True:

        while l_pointer <= r_pointer and arr[l_pointer] <= pivot:
            l_pointer += 1

        while l_pointer <= r_pointer and arr[r_pointer] >= pivot:
            r_pointer -= 1

        if r_pointer < l_pointer:
            break

        arr[l_pointer], arr[r_pointer] = arr[r_pointer], arr[l_pointer]
    arr[start], arr[r_pointer] = arr[r_pointer], arr[start]

    quick_sorting(start, r_pointer)
    # print(arr)
    quick_sorting(r_pointer + 1, limit)


quick_sorting(0, len(arr))

for n in arr:
    sys.stdout.write(f"{n}\n")
