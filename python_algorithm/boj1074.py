import sys

N, r, c = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

delta = [(0, 0), (0, 1),
         (1, 0), (1, 1)]

board = []
# row and colum count
row_col_cnt = 2 ** N
for i in range(row_col_cnt):
    board.append([0] * row_col_cnt)


def recurrsion(starting_point, increment):
    print("start ; ", starting_point)
    for d in delta:
        starting_point = 2 + starting_point[0], 2 + starting_point[1]
        for d in delta:
            x, y = d[0] + starting_point[0], d[1] + starting_point[1]
            print("recur1ssion : ", x, y)
            board[x][y] = increment
            increment += 1

    return increment


# recurrsion((0,0), 0)


def divide(starting_point, pow_num, increment):
    for i, d in enumerate(delta):
        x, y = (starting_point[0] + (2 ** pow_num * d[0]), starting_point[1] + (2 ** pow_num * d[1]))
        print("divide : ", x, y)
        increment = recurrsion((x, y), increment)

    return increment


print(2 ** (N - 1))

pow_num = 2
increment = divide((0, 0), pow_num, 0)
increment = divide((0, 2 ** (N - 1)), pow_num, increment)
increment = divide((2 ** (N - 1), 0), pow_num, increment)
increment = divide((2 ** (N - 1), 2 ** (N - 1)), pow_num, increment)

for b in board:
    print(b)

#
# def divide_board(n):
#     if n == 0:
#         return recurrsion((0, 0), 0)
#     print(n)
#     n -= 1
#     for d in delta:
#         x, y = (starting_point[0] + (2 ** pow_num * d[0]), starting_point[1] + (2 ** pow_num * d[1]))
#         print(x, y)
#     # divide_board(n)
#     recurrsion(n, )
#
#
# divide_board(N)
# 3 3 3
