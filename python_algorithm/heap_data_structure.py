def swap_num(arr, idx1, idx2):
    tmp = arr[idx1]
    arr[idx1] = arr[idx2]
    arr[idx2] = tmp


# count = int(input())
import os

# count = map(int, os.read(0, os.stat(0).st_size).splitlines())

read = os.read(0, 100)
print(os.stat(0))
print(read.splitlines())

exit()


print(count)
arr = [None]

for _ in count:

    i = int(input())

    if i == 0:
        length = len(arr) - 1
        if length == 0:
            # length == 1 -=> 어떤 데이터도 list에 없다를 의미
            print(0)
        else:

            if length == 1:
                print(arr.pop(1))
            else:
                # pop
                max_num = arr[1]
                parent_idx = 1

                left_child = parent_idx * 2
                right_child = parent_idx * 2 + 1
                # print()
                # print("ori arr :", arr)

                arr[1] = arr[-1]
                del arr[-1]

                length -= 1

                # len = 2 / l : 2 / r :3
                if length == 2:
                    if arr[left_child] > arr[parent_idx]:
                        swap_num(arr, left_child, parent_idx)
                        print(max_num)
                        continue
                # print(f"changed : {arr}")
                while length >= right_child:
                    # print(f"parent : {arr[parent_idx]}, \n"
                    #      f"l : {arr[left_child]}, r : {arr[right_child]}")

                    if arr[left_child] > arr[right_child]:
                        child_val = arr[left_child]
                        child_idx = left_child
                    else:
                        child_val = arr[right_child]
                        child_idx = right_child

                    if arr[parent_idx] < child_val:
                        swap_num(arr, parent_idx, child_idx)
                        parent_idx = child_idx
                    else:
                        break

                    left_child = parent_idx * 2
                    right_child = parent_idx * 2 + 1
                    # print(arr)
                # print("max : ", max_num)
                print(max_num)

    else:
        arr.append(i)
        curr_index = len(arr) - 1
        parent_idx = curr_index // 2

        while curr_index > 1 and parent_idx >= 1:

            if arr[parent_idx] < arr[curr_index]:
                swap_num(arr, parent_idx, curr_index)
            else:
                break
            curr_index = parent_idx
            parent_idx = curr_index // 2
