import sys

sys.setrecursionlimit(100000)
A, B, C = sys.stdin.readline().rstrip().split(' ')
# CONST(read only) variable
A = int(A)
B = int(B)
C = int(C)

# stack 생성 = 3 // 2**3 번!! (8번) 거듭제곱함
def recurrsion_mod(a, b, c):
    if b == 1:
        return a
    print("b : ", b)
    b //= 2
    result = recurrsion_mod(a, b, c)
    print("re : ", result**2)
    # result = (result ** 2) % c
    # print("mod : ", result)
    return (result ** 2)

answer = recurrsion_mod(A, B, C)

print(answer)

# 3 12 41


# # Base Condition으로 수렴해야 한다.!!
# # 더이상 나눌 수 없다.
# # left ~ mid // mid ~ right
# def divide_list(left, right):
#     mid = (left + right) // 2
#
#     if left == mid or mid == right:
#         return A ** (right - left + 1)
#
#     left_divied_result = divide_list(left, mid)
#
#     right_divied_result = divide_list(mid + 1, right)
#
#     print(left_divied_result * right_divied_result, " / ", (left_divied_result * right_divied_result) % C)
#     return left_divied_result * right_divied_result
#
#
# answer = divide_list(0, B - 1)
#
# sys.stdout.write(f"{answer%C}")
