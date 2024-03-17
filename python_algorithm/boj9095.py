import sys

# 초기값을 정하기 중요!!

table = [0] * 11

table[1] = 1  # 1
table[2] = 2  # 1+1, 2
table[3] = 4  # 1+1+1, (2+1, 1+2), 3
table[4] = 8  # 1+1+1+1, (2+1+1, 1+2+1, 1+1+2), 2+2, (3+1, 1+3), 4

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


