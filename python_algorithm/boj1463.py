import sys

# 점화식에서 초기값 정의를 잘야해 한다.

n = int(sys.stdin.readline().rstrip())

dp = [0] * ((10 ** 6) + 1)

dp[1] = 0
dp[2] = 1
dp[3] = 1

num = 4
while num <= n:

    min_arr = [dp[num - 1] + 1]

    if num % 3 == 0:
        min_arr.append(dp[num // 3] + 1)

    if num % 2 == 0:
        min_arr.append(dp[num // 2] + 1)

    dp[num] = min(min_arr)
    # print("num : ", num)
    # print(cmp1, cmp2)
    #
    # print()
    num += 1
# print(dp[:11])
print(dp[n])

#
# dp_dict = {1: 0, 2: 1, 3: 1, 4: 2, 5: 3, 6: 2, 7: 3, 8: 3, 9: 2, 10: 3, 11: 4, 12: 3, 13: 4, 14: 4, 15: 4, 16: 4, 17: 5, 18: 3, 19: 4, 20: 4, 21: 4}
#
# sentinel = 10 ** 6
#
# i = 22
# while i <= n:
#     N = i
#
#     min_val = sentinel
#
#     if N % 3 == 0:
#         dp_val = dp_dict[N // 3]
#         if dp_val < min_val:
#             min_val = dp_val
#
#     if N % 2 == 0:
#         dp_val = dp_dict[N // 2]
#         if dp_val < min_val:
#             min_val = dp_val
#
#     dp_minus = dp_dict[N - 1]
#     if dp_minus < min_val:
#         min_val = dp_minus
#
#     if min_val != sentinel:
#         assert "It's impossible"
#
#     dp_dict[i] = min_val + 1
#
#     i += 1
#
# sys.stdout.write(f"{dp_dict[n]}")
