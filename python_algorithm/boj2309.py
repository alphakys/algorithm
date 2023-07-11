import random
import sys
import numpy as np

k = 0
while k < 2:
    try:
        a = np.random.randint(1, 100, 2)

        arr = [7, 8, 10, 13, 19, 20, 23]

        if any([n in arr for n in a]):
            continue
        # for _ in range(9):
        #     n = int(sys.stdin.readline())
        #     arr.append(n)

        arr = arr + a.tolist()

        random.shuffle(arr)
        print(arr)

        sums = sum(arr)
        j = 0
        while j <= 7:
            for i in range(j+1, 9):
                # print(i)
                tmp_sum = arr[j] + arr[i]
                print(arr[j], ' ', arr[i])
                if sums - tmp_sum == 100:
                    first_remove = arr[j]
                    second_remove = arr[i]
                    # print(first_remove, second_remove)
                    arr.remove(first_remove)
                    arr.remove(second_remove)

                    sys.stdout.write('\n'.join([str(n) for n in sorted(arr)]))
                    exit()
            j += 1
        k += 1
    except Exception as e:
        print(e)

