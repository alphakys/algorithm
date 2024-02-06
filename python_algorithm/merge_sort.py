import sys
import array

sys.setrecursionlimit(10000)


def swap_num(arr, swap1, swap2):
    tmp = arr[swap1]
    arr[swap1] = arr[swap2]
    arr[swap2] = tmp


def merge_array(arr, tmp, left, right):
    """
    :param arr: 원본 array
    :param tmp: merge 정렬 하기 전에 임시로 정렬된 array
    """
    pivot = (left + right) // 2 + 1
    mid = pivot

    tmp_arr_idx = left

    while tmp_arr_idx <= right:
        if mid > right:
            tmp[tmp_arr_idx] = arr[left]
            left += 1
            tmp_arr_idx += 1
            continue
        elif left == pivot:
            tmp[tmp_arr_idx] = arr[mid]
            mid += 1
            tmp_arr_idx += 1
            continue

        if arr[left] < arr[mid]:
            target_idx = left
            left += 1
        else:
            target_idx = mid
            mid += 1

        # 비교하고자 하는 array가 limit을 넘으면 남은 array의 값을 일괄적으로 tmp에 push한다.
        tmp[tmp_arr_idx] = arr[target_idx]
        tmp_arr_idx += 1


def split_array(arr, left_idx, right_idx):
    """
    split array는 토너먼트 대전 상대를 나누는 함수
    :param arr:
    :param left_idx:
    :param right_idx:
    :return:
    """
    # left_idx = 0
    # right_idx = len(arr)
    mid_idx = (left_idx + right_idx) // 2

    if left_idx == mid_idx:
        # print(f"split is completed // left {left_idx} , mid {mid_idx} right : {right_idx}")
        # print(f"토너먼트 상대 : {arr[left_idx]} vs {arr[right_idx]}")
        if arr[left_idx] > arr[right_idx]:
            swap_num(arr, left_idx, right_idx)

        return

    split_array(arr, left_idx, mid_idx)
    split_array(arr, mid_idx + 1, right_idx)

    # print("!!!merge 전!!! : ", arr)
    # print(f"merge process : {left_idx}, {right_idx}")
    merge_array(arr, tmp_arr, left_idx, right_idx)

    while left_idx <= right_idx:
        arr[left_idx] = tmp_arr[left_idx]
        left_idx += 1


# raw_input = [random.randint(0, 2**30) for _ in range(100000)]
# answer = copy.deepcopy(raw_input)

count = int(sys.stdin.readline())

input_arr = array.array('l', [0 for i in range(count)])

for _ in range(count):
    i = int(sys.stdin.readline())
    input_arr[_] = i

tmp_arr = array.array('l', [0 for i in range(count)])

split_array(input_arr, 0, count - 1)

for _ in input_arr:
    sys.stdout.write(f'{_}\n')
# raw_input = sorted(raw_input)
#
# for i, n in enumerate(raw_input):
#
#     v = answer[i]
#     assert n == v, f"index : {i}, {n}, {v}"
# print(n)


# 큰 수 array
# 작은 수 array 구분한다 하더라도 작은 수 array에 있는 수가 큰 수 array에 있는 수보다 클 가능성도 있다.

# first condition : 더이상 쪼갤 수 없을 때까지 쪼갠다.
# 재귀로 쪼갠다. 그렇다면 원자까지 쪼개는 조건 설정해야함
# second condition : 원자들을 대수 비교하여 정렬해간다.
