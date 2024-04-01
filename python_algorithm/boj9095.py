import sys

# 초기값을 정하기 중요!!
N = 4

vis = [False] * 4
container = [0] * N

def back_track(idx):

    if sum(container) == 4:
        print("result : ", container)
        return

    for num in range(0, 4):

        if not vis[num] and idx < N:
            container[idx] = num
            # print("n : ", num)
            # print("container : ", container)
            # print()
            back_track(idx + 1)

back_track(0)

n = 5

dp = [0] * (n + 1)

dp[1] = 1
dp[2] = 2
dp[3] = 4


dp_start_num = 4

while dp_start_num <= n:
    dp[dp_start_num] = dp[dp_start_num - 1] + dp[dp_start_num - 2] + dp[dp_start_num - 3]




#  1

#  1 1

#  2

#  1 1 1
#  2 1
#
#  1 2
#
#  3

"""
1 1 1 1
1 2 1
2 1 1
3 1

1 1 2
2 2

1 3

"""

"""
1 1 1 1 1
1 2 1 1 
2 1 1 1
1 1 2 1
3 1 1

1 1 1 2
3 2
1 2 2
2 1 2
 
3 1 1
1 3 


2 2

1 3

"""






# table = [0] * 11
# dp = [0] * 11
#
# table[1] = 1  # 1
# dp[1] = [[1], [0], [0], [0]]
#
# table[2] = 2  # 1+1,
#               # 2
# dp[2] = [[1], [1], [0], [0]]
#
# table[3] = 4  # 1+1+1, (2+1,
#               # 1+2), 3
# dp[3] = [[1], [2], [1], [0]]
#
# table[4] = 7  # 1+1+1+1, (2+1+1, 1+2+1, (3+1
#                # 1+1+2), 2+2,
# #               1+3
# dp[4] = [[1], [3], [1], [2]]
#
# table[5] = 13  # 1+1+1+1+1, 2+1+1+1, 1+2+1+1, 1+1+2+1, 2+2+1, 3+1+1, 1+3+1
#                # 1+1+1+2, 2+1+2, 1+2+2, 3+2
#                # 1+1+3, 2+3
#


# then D[5] =


# read = sys.stdin.readline
#
# T = int(read().rstrip())
#
# table = [0] * 11
#
# print(table[10])
#
# for _ in range(T):
#
#     N = int(read().rstrip())
