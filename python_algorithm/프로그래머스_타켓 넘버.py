from itertools import product

numbers = [1, 1, 1, 1, 1]
container = [0] * len(numbers)
target = 3

answer = 0

def solution(numbers, target):

    if not numbers and target ==0:
        return 1
    elif not numbers:
        return 0
    print("arr : ", numbers)
    print("target : ", target)
    print()
    return solution(numbers[1:], target - numbers[0]) + solution(numbers[1:], target+numbers[0])

solution(numbers, 3)

# def solution(numbers, target, idx=0):
#     global answer
#     if idx == len(numbers):
#         if sum(container) == target:
#             answer += 1
#         return
#
#     for i in range(2):
#         if i == 0:
#             container[idx] = numbers[idx] * -1
#
#         else:
#             container[idx] = numbers[idx]
#
#         solution(numbers, target, idx + 1)
#
#
# solution(numbers, 3)
#
# print(answer)
# from itertools import product
#
# product = product([0, 1], repeat=len(l))
#
# target = 3
# answer = 0
# for pro in product:
#
#     result = [l[idx] if _ == 0 else l[idx] * -1 for idx, _ in enumerate(pro)]
#     if sum(result) == target:
#         answer += 1
#
# print(answer)
