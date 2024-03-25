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


count_l = [0] * 20000001


def count_adder(x):
    x = int(x)
    count_l[x + 10000000] += 1
    return x


# start는 이전 mid 보다 하나 큰 수.
# 따라서 mid에서 target num을 찾았다면
# 현재의 start는

def main() -> None:
    N = int(sys.stdin.readline().rstrip())

    arr = sorted(list(map(count_adder, sys.stdin.readline().rstrip().split(' '))))
    M = int(sys.stdin.readline().rstrip())
    target_nums = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

    io = StringIO()

    for n in target_nums:
        is_exists = binary_search(n, arr)

        io.write(f"{is_exists and count_l[n + 10**7]} ")

    print(io.getvalue())


if __name__ == '__main__':
    main()
