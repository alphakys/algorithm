def swap_num(arr, idx1, idx2):
    tmp = arr[idx1]
    arr[idx1] = arr[idx2]
    arr[idx2] = tmp


switch_validation = lambda array, x, y: abs(array[x]) > abs(array[y]) \
                    or (abs(array[x]) == abs(array[y]) and array[x] > array[y])

import sys

count = int(sys.stdin.readline())

arr = []

for _ in range(count):

    i = int(sys.stdin.readline())

    if i == 0:
        length = len(arr)

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
                    if switch_validation(arr, parent_idx, left_child_idx):
                        swap_num(arr, parent_idx, left_child_idx)
                    break

                if abs(arr[left_child_idx]) < abs(arr[left_child_idx + 1]):
                    # min_val = abs(arr[left_child_idx])
                    child_idx = left_child_idx
                else:
                    # min_val = abs(arr[left_child_idx + 1])
                    child_idx = left_child_idx + 1

                # parent_val = arr[parent_idx]
                # True and

                if switch_validation(arr, parent_idx, child_idx):
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

        # print(f"i : {i}")
        while curr_index > 0:

            if switch_validation(arr, parent_idx, curr_index):
                    # abs(arr[parent_idx]) > abs(arr[curr_index]) \
                    # or (abs(arr[parent_idx]) == abs(arr[curr_index]) and arr[parent_idx] > arr[curr_index]):
                swap_num(arr, parent_idx, curr_index)
                curr_index = parent_idx
                parent_idx = (curr_index + 1) // 2 - 1
            else:
                break
            print(arr)

        print("i index arr : ", arr)
        print()

print(arr)
