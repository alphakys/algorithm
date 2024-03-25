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
            return 1, start, mid_ptr, end
        elif arr[mid_ptr] > n:
            end = mid_ptr - 1
        else:
            start = mid_ptr + 1

        mid_ptr = (start + end) // 2

    return 0


def lower_bound(target, arr):
    start = 0
    end = len(arr)
    mid = (start + end) // 2

    while start < end:

        if arr[mid] >= target:
            end = mid
        else:
            start = mid + 1
        mid = (start + end) // 2

    return start

def upper_bound(target, arr):
    start = 0
    end = len(arr)
    mid = (start + end) // 2

    while start < end:

        if arr[mid] > target:
            end = mid
        else:
            start = mid + 1
        mid = (start + end) // 2

    return start
    #0  1  2 / target= 3
    # [0, 1]


    # s: 0 / mid: 4 / e: 8
    # s: 0 / mid: 2 / e: 4
    # s: 3 / mid: 3 / e: 4


# v[i - 1] < target <= v[i]
# v[i - 1] <= target < v[i]


def main() -> None:
    # N = int(sys.stdin.readline().rstrip())
    # arr = sorted(list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))))
    #      0  1  2  3  4  5  6  7  8
    arr = [1, 1, 1, 2, 2, 2, 2, 3, 4]

    res = upper_bound(3, arr)

    print(res)
    io = StringIO()

    # for n in target_nums:
    #     io.write(f"{binary_search(n, arr)}\n")
    #
    # print(io.getvalue())


if __name__ == '__main__':
    main()
