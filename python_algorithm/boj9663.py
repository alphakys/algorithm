import sys
from itertools import permutations

# N = int(sys.stdin.readline().rstrip())

# 1. queen은 같은 row, column에 놓여서는 안된다.
# 2. queen은 대각선에 위치해선 안된다.
N = 10
board = [[0] * N for _ in range(N)]

#
# def print_board():
#     for b in board:
#         print(b)
#
#
# def reset_board():
#     for i in range(N):
#         for j in range(N):
#             board[i][j] = 0
# dp_table = set()


def mark_board(permu):
    dx = (1, -1,)
    dy = (1, -1,)

    for grid_point in permu[1:]:
        for _ in range(2):
            # print(grid_point[0], dx[_])
            x = grid_point[0] + dx[_]
            y = grid_point[1] + dy[_]

            while x < N and y < N:
                if (x, y) in permu:
                    # print("conflict : ", grid_point, (x, y))

                    # dp_table.add((grid_point, (x, y)))

                    # print()
                    return False
                else:
                    x += dx[_]
                    y += dy[_]

    return True


p = list(permutations(range(N), N))

queen_permutation = []
for element in p:
    queen_permutation.append([(i, element[i]) for i in range(N)])

answer = 0
for permu in queen_permutation:

    # for dp in dp_table:
    #     if dp in permu:
    #         continue

    result = mark_board(permu)
    if not result:
        continue
    else:
        # for p in permu:
        #     px, py = p
        #     board[px][py] = 1
        answer += 1

# print(dp_table)
sys.stdout.write(f"{answer}")
