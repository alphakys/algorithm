import os


def swap_num(arr, idx1, idx2):
    tmp = arr[idx1]
    arr[idx1] = arr[idx2]
    arr[idx2] = tmp


def create_heap_sort(nums):
    arr = []

    for n in nums:
        arr.append(n)

        curr_index = len(arr) - 1
        parent_idx = (curr_index + 1) // 2 - 1

        while curr_index > 0:

            if arr[parent_idx] > arr[curr_index]:
                swap_num(arr, parent_idx, curr_index)
                curr_index = parent_idx
                parent_idx = (curr_index + 1) // 2 - 1
            else:
                break

    return arr


def h_pop(arr):
    count = len(arr)
    length = count
    ans = []
    for _ in range(count):

        min_num = arr[0]
        parent_idx = 0
        left_child_idx = parent_idx * 2 + 1

        arr[0] = arr[-1]

        while length > left_child_idx:

            if length - 1 == left_child_idx:
                if arr[parent_idx] > arr[left_child_idx]:
                    swap_num(arr, parent_idx, left_child_idx)
                break

            if arr[left_child_idx] < arr[left_child_idx + 1]:
                min_val = arr[left_child_idx]
                child_idx = left_child_idx
            else:
                min_val = arr[left_child_idx + 1]
                child_idx = left_child_idx + 1

            if arr[parent_idx] > min_val:
                swap_num(arr, parent_idx, child_idx)
                parent_idx = child_idx
                left_child_idx = parent_idx * 2 + 1

            else:
                break

        del arr[-1]
        length -= 1
        ans.append(min_num)

    return ans


import sys

count = int(sys.stdin.readline())

arr = []

for _ in range(count):

    i = int(sys.stdin.readline())

    if i == 0:
        length = len(arr)
        # count = len(arr)
        # length = count
        if length == 0:
            # length == 1 -=> 어떤 데이터도 list에 없다를 의미
            print(int(0))
        else:
            min_num = arr[0]
            parent_idx = 0
            left_child_idx = parent_idx * 2 + 1

            arr[0] = arr[-1]

            while length > left_child_idx:

                if length - 1 == left_child_idx:
                    if arr[parent_idx] > arr[left_child_idx]:
                        swap_num(arr, parent_idx, left_child_idx)
                    break

                if arr[left_child_idx] < arr[left_child_idx + 1]:
                    min_val = arr[left_child_idx]
                    child_idx = left_child_idx
                else:
                    min_val = arr[left_child_idx + 1]
                    child_idx = left_child_idx + 1

                if arr[parent_idx] > min_val:
                    swap_num(arr, parent_idx, child_idx)
                    parent_idx = child_idx
                    left_child_idx = parent_idx * 2 + 1

                else:
                    break

            del arr[-1]
            length -= 1
            # os.write(min_num)
            sys.stdout.write(f"{min_num}\n")
    else:
        arr.append(i)

        curr_index = len(arr) - 1
        parent_idx = (curr_index + 1) // 2 - 1

        while curr_index > 0:

            if arr[parent_idx] > arr[curr_index]:
                swap_num(arr, parent_idx, curr_index)
                curr_index = parent_idx
                parent_idx = (curr_index + 1) // 2 - 1
            else:
                break



# import sys
#
#
# def swap_num(arr, idx1, idx2):
#     tmp = arr[idx1]
#     arr[idx1] = arr[idx2]
#     arr[idx2] = tmp
#
#
# count = int(sys.stdin.readline())
#
# arr = [None]
#
# for _ in range(count):
#
#     i = int(sys.stdin.readline())
#
#     if i == 0:
#         length = len(arr) - 1
#         if length == 0:
#             # length == 1 -=> 어떤 데이터도 list에 없다를 의미
#             print(int(0))
#         else:
#
#             if length == 1:
#                 print(int(arr.pop(1)))
#             else:
#                 # pop
#                 max_num = arr[1]
#                 parent_idx = 1
#
#                 left_child = parent_idx * 2
#                 right_child = parent_idx * 2 + 1
#
#                 arr[1] = arr[-1]
#                 del arr[-1]
#
#                 length -= 1
#
#                 # len = 2 / l : 2 / r :3
#                 if length == 2:
#                     if arr[left_child] > arr[parent_idx]:
#                         swap_num(arr, left_child, parent_idx)
#                         print(int(max_num))
#                         continue
#                 # print(f"changed : {arr}")
#                 while length >= right_child:
#                     # print(f"parent : {arr[parent_idx]}, \n"
#                     #      f"l : {arr[left_child]}, r : {arr[right_child]}")
#
#                     if arr[left_child] > arr[right_child]:
#                         child_val = arr[left_child]
#                         child_idx = left_child
#                     else:
#                         child_val = arr[right_child]
#                         child_idx = right_child
#
#                     if arr[parent_idx] < child_val:
#                         swap_num(arr, parent_idx, child_idx)
#                         parent_idx = child_idx
#                     else:
#                         break
#
#                     left_child = parent_idx * 2
#                     right_child = parent_idx * 2 + 1
#                     # print(arr)
#                 # print("max : ", max_num)
#                 print(int(max_num))
#
#     else:
#         arr.append(i)
#         curr_index = len(arr) - 1
#         parent_idx = curr_index // 2
#
#         while curr_index > 1 and parent_idx >= 1:
#
#             if arr[parent_idx] < arr[curr_index]:
#                 swap_num(arr, parent_idx, curr_index)
#             else:
#                 break
#             curr_index = parent_idx
#             parent_idx = curr_index // 2
