import sys
import numpy as np

# A, B = [int(n) for n in sys.stdin.readline().split()]

A = 10
B = 100

sum_formula = lambda x: int((x * (1+x))/2)

sum_ = 0
for i in range(1, 20):
    print(f'{sum_formula(i)} 까지 {i}')
    if sum_formula(i) > A: #and sum_formula(i) >= B:
        # print(sum_formula(i))
        sum_ += i*i
        # print((sum_formula(i) - A) * i)

    # elif sum_formula(i) <= B:
    #
    #     print((B - sum_formula(i)) * i)

print(sum_)

arr = []
for i in range(1, 46):
    for j in range(i):
        arr.append(i)

sys.stdout.write(f'{str(sum(arr[A-1:B]))}')

#
# arr = []
# for i in range(1, 46):
#     for j in range(i):
#         arr.append(i)
#
# sys.stdout.write(f'{str(sum(arr[A-1:B]))}')
