import heapq


def heap_insert(l, num):
    """
    # insert operation Bottom Up
    """
    l.append(num)
    curr_idx = len(l) - 1
    parent_idx = curr_idx // 2

    while parent_idx > 0 and l[parent_idx] < num:
        l[parent_idx], l[curr_idx] = l[curr_idx], l[parent_idx]
        curr_idx = parent_idx
        parent_idx = curr_idx // 2


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

operations = ["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]
operations = ["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]
# operations = ["D -1", "D 1", "D 1"]
min_heap = []
max_heap = [None]

for op in operations:
    if op == "D -1":
        if min_heap:
            ret = heapq.heappop(min_heap)
            max_heap.remove(ret)
            print("min : ", ret)
            print("min heap : ", min_heap, max_heap)
    elif op == "D 1":
        if max_heap and len(max_heap) != 1:
            ret = heap_delete(max_heap)

            min_heap.remove(ret)
            print("max : ", ret)
            print("max heap : ", max_heap, min_heap)

    else:
        heapq.heappush(min_heap, int(op.split(' ')[1]))
        heap_insert(max_heap, int(op.split(' ')[1]))

if min_heap:
    answer = [max(min_heap), min(min_heap)]
else:
    answer = [0, 0]

print(answer)