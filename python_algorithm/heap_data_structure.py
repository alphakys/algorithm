from array import array

count = int(input())


def switch_val(arr, curr_index):
    curr_num = arr[curr_index]

    parent_idx = curr_index // 2
    parent_num = arr[parent_idx]

    if parent_idx < 1:
        return

    if parent_num < curr_num:
        tmp = arr[parent_idx]
        arr[parent_idx] = curr_num
        arr[curr_index] = tmp

        switch_val(arr, parent_idx)


arr = [None]


def swap_num(arr, idx1, idx2):
    tmp = arr[idx1]
    arr[idx1] = arr[idx2]
    arr[idx2] = tmp


def swap_child_node(arr: list, parent_index):
    left_child = parent_index * 2
    right_child = parent_index * 2 + 1

    if len(arr) < left_child:
        return

    if right_child > len(arr):
        swap_num(arr, parent_index, left_child)
        del arr[left_child]
    else:

        if arr[left_child] > arr[right_child]:
            swap_num(arr, left_child, parent_index)
            arr[left_child] = arr[right_child]

        else:
            swap_num(arr, parent_index, right_child)

    #      5
    #   4     2
    # 1   3


    #      4
    #   3     2
    # 1

        del arr[right_child]


for _ in range(count):

    i = int(input())

    if i == 0:
        length = len(arr)
        if length == 1:
            print(0)
        else:
            # pop
            if length > 2:
                max_num = arr[1]
                parent_idx = 1

                left_child = parent_idx * 2
                right_child = parent_idx * 2 + 1

                # 무조건 swap된 node를 parent로 하되 parent의 left or right child가
                # length를 넘기면 break 된다.

                while length >= right_child:

                    if (length - 1) == left_child:
                        swap_num(arr, left_child, parent_idx)
                        parent_idx = left_child
                    else:
                        if arr[left_child] > arr[right_child]:
                            swap_num(arr, left_child, parent_idx)
                            parent_idx = left_child
                        else:
                            swap_num(arr, parent_idx, right_child)
                            parent_idx = right_child

                    left_child = parent_idx * 2
                    right_child = parent_idx * 2 + 1

                print("max : ", max_num)
                # print(max_num)
                arr.pop(parent_idx)

            else:
                print(arr.pop(1))

    else:
        arr.append(i)
        curr_index = len(arr) - 1
        parent_idx = curr_index // 2

        while curr_index > 1 and parent_idx >= 1:

            if arr[parent_idx] < arr[curr_index]:
                swap_num(arr, parent_idx, curr_index)

            curr_index = parent_idx
            parent_idx = curr_index // 2

    print(arr)


  #      5
  #   4     2
  # 1   3

  #      4
  #   3     2
  # 1

  #      3
  #   1     2
  # 4


  #      2
  #   1     3

#
# for _ in range(count):
#     i = int(input())
#     curr_index = len(arr)
#     if i == 0:
#         if curr_index == 0:
#             print(0)
#         else:
#             # pop
#             print(arr.pop(0))
#             if len(arr) > 1 and arr[1] > arr[0]:
#                 tmp = arr[0]
#                 arr[0] = arr[1]
#                 arr[1] = tmp
#
#     else:
#
#         # insert
#         parent_index = search_parent_idx(curr_index)
#
#         if parent_index < 0:
#             arr.append(i)
#         else:
#             parent_val = arr[parent_index]
#             if parent_val < i:
#                 arr[parent_index] = i
#                 arr.append(parent_val)
#                 switch_val(arr, parent_index)
#
#             else:
#                 arr.append(i)
#     print(arr)
