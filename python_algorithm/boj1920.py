import sys
from io import StringIO


def binary_search(n, arr):
    start = 0
    end = len(arr) - 1
    mid_ptr = (start + end) // 2

    # start mid를 고려한다.
    # break point
    while start <= mid_ptr:

        if arr[mid_ptr] == n:
            return 1
        elif arr[mid_ptr] > n:
            end = mid_ptr - 1
        else:
            start = mid_ptr + 1

        mid_ptr = (start + end) // 2

    return 0


def main() -> None:
    N = int(sys.stdin.readline().rstrip())
    arr = sorted(list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))))
    M = int(sys.stdin.readline().rstrip())
    target_nums = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

    io = StringIO()

    for n in target_nums:
        io.write(f"{binary_search(n, arr)}\n")

    print(io.getvalue())


if __name__ == '__main__':
    main()
