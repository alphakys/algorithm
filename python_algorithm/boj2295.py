import sys
from itertools import *


def binary_search(arr, target):
    start = 0
    end = len(arr)
    mid = (start + end) // 2

    answer = False
    while start < end:
        if arr[mid] == target:
            answer = True
            break
        elif arr[mid] > target:
            end = mid
        else:
            start = mid + 1

        mid = (start + end) // 2

    return answer


def main() -> None:
    N = int(sys.stdin.readline().rstrip())
    arr = [0] * N
    for _ in range(N):
        arr[_] = int(sys.stdin.readline().rstrip())

    # import random
    # arr = [random.randint(1, 50) for _ in range(30)]
    arr.sort()

    # print(arr)

    length = len(arr) - 1
    last_num = arr[length]
    pl = length - 1
    pr = length - 1

    while pr > 1:
        # print(pl, pr)

        if pl < 0:
            pr -= 1
            pl = pr
            continue
        target_num = last_num - (arr[pr] + arr[pl])

        if binary_search(arr, target_num):
            # print("last : ", last_num)
            # print(f"pl idx : {pl} // pr idx {pr}")
            # print(f"pl val : {arr[pl]} // pr val : {arr[pr]} t : {target_num}")
            print(last_num)
            break
        pl -= 1


if __name__ == '__main__':
    main()
