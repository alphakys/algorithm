import sys
from io import StringIO


def heap_insert(l, num):
    """
    # insert operation Bottom Up
    """
    # insert value in last_index
    l.append(num)
    # last_indxe = curr_index
    curr_idx = len(l) - 1
    # parent index
    parent_idx = curr_idx // 2
    while parent_idx > 0 and l[parent_idx] < num:
        l[parent_idx], l[curr_idx] = l[curr_idx], l[parent_idx]
        curr_idx = parent_idx
        parent_idx = curr_idx // 2
    # print("insert : num -> ", l)


def heap_delete(l):
    """
    # delete operation Top Down
    """
    if len(l) == 1:
        return 0
    max_val = l[1]

    # 마지막 index의 값을 root로 swap and Top down operation
    l[1] = l[-1]
    del l[-1]
    length = len(l) - 1

    parent = 1
    left_idx = parent * 2
    right_idx = parent * 2 + 1

    # left child의 index가 사이즈 보다 크면 leaf node
    while length >= left_idx:

        if length == left_idx or l[left_idx] > l[right_idx]:
            gt_num = l[left_idx]
            gt_idx = left_idx
        else:
            gt_num = l[right_idx]
            gt_idx = right_idx

        if gt_num > l[parent]:
            l[gt_idx], l[parent] = l[parent], l[gt_idx]
            parent = gt_idx
            left_idx = parent * 2
            right_idx = parent * 2 + 1

        else:
            break

    return max_val


def main() -> None:
    N = int(sys.stdin.readline().rstrip())
    l = [None]

    io = StringIO()
    for _ in range(N):
        n = int(sys.stdin.readline().rstrip())

        if n == 0:
            # str += heap_delete(l)
            io.write(f'{heap_delete(l)}\n')
        else:
            heap_insert(l, n)

    print(io.getvalue())

if __name__ == '__main__':
    main()
