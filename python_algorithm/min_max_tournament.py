import numpy as np

arr = np.random.randint(1, 1000, 10)

start_pos = 0
end_pos = arr.__len__()-1

length = int(arr.__len__())

print(arr)

print(length//2//2)

if length % 2 == 0:
    while start_pos < length//2:
        print((arr[start_pos], arr[start_pos+1]), (arr[end_pos], arr[end_pos-1]))

        # print(arr[end_pos], arr[end_pos - 1])
        left_max = arr[start_pos] if arr[start_pos] >= arr[start_pos + 1] else arr[start_pos + 1]
        right_max = arr[end_pos] if arr[end_pos] >= arr[end_pos - 1] else arr[end_pos - 1]

        print(f'leftmax : {left_max}, rigth_max : {right_max}')

        start_pos += 2
        end_pos -= 2

    # for i in range(length // 4 + 1):
    #
    #     print(arr[start_pos] , arr[start_pos+1])
    #     print(arr[end_pos], arr[end_pos - 1])
    #     left_max = arr[start_pos] if arr[start_pos] >= arr[start_pos+1] else arr[start_pos+1]
    #     right_max = arr[end_pos] if arr[end_pos] >= arr[end_pos-1] else arr[end_pos-1]
    #
    #     start_pos += 2
    #     end_pos -= 2
        # print(f'leftmax : {left_max}, rigth_max : {right_max}')
else:
    while start_pos != end_pos:
        print(arr[start_pos], arr[end_pos])

        # print(arr[end_pos], arr[end_pos - 1])
        # left_max = arr[start_pos] if arr[start_pos] >= arr[start_pos + 1] else arr[start_pos + 1]
        # right_max = arr[end_pos] if arr[end_pos] >= arr[end_pos - 1] else arr[end_pos - 1]

        start_pos += 1
        end_pos -= 1
