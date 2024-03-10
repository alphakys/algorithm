import sys

sys.setrecursionlimit(10000000)
A, B, C = sys.stdin.readline().rstrip().split(' ')
# CONST(read only) variable
A = int(A)
B = int(B)
C = int(C)

# 핵심 아이디어
# A mod B -> C // A^2 mod B -> C^2

# 2^90 mod C

# 2^90 = 2^45 * 2^45 mod C
# 2^90 = { (2^45 mod C) * (2^45 mod C) } mod C



# 2^91 = (2^45 * 2^45 * 2) mod C
# 2^91 = { (2^45 mod C) * (2^45 mod C) * (2 mod C) } mod C

# half = B//2
# print(f"{half} {half} {2 ** (B % 2)}")
# modulo_statement = half * half * 2 ** (B % 2)

# stack 생성 = 3 // 2**3 번!! (8번) 거듭제곱함
def recurrsion_mod(b):
    half = b // 2
    if half < 460:
        half_modulo = (A ** half) % C
        return ((half_modulo**2) * ((A ** (b % 2)) % C) ) % C

    result = recurrsion_mod(half)
    modulo = (result**2 * ((A ** (b % 2)) % C)) % C
    return modulo

answer = recurrsion_mod(B)
sys.stdout.write(f"{answer}")

# 2 124 443

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
