import sys
from itertools import permutations


def print_board(board):
    for b in board:
        print(b)

    print()


def reset_board():
    for i in range(N):
        for j in range(N):
            board[i][j] = 0


def numbering_board():
    n = 1
    for i in range(N):
        for j in range(N):
            board[i][j] = n
            n += 1


# N = int(sys.stdin.readline().rstrip())

# 1. queen은 같은 row, column에 놓여서는 안된다.
# 2. queen은 대각선에 위치해선 안된다.
N = 4
board = [[0] * N for _ in range(N)]

marking_board = [[0] * N for _ in range(N)]

numbering_board()

vis = [False] * N
container = [0] * N

print_board(board)

def mark_board(grid_point):
    dx = (1, 1,)
    dy = (1, -1,)

    for _ in range(2):
        x = grid_point[0] + dx[_]
        y = grid_point[1] + dy[_]

        while 0 <= x < N and 0 <= y < N:
            marking_board[x][y] = 1
            x += dx[_]
            y += dy[_]

    print_board(marking_board)


def permutation_board(idx, depth):
    if depth == 4:
        print("container : ", container)
        # print(arr[0][container[0]], arr[1][container[1]])
        return

    for num in range(N):
        if not vis[num]:
            print("board 진입 : ", board[depth][num])
            print("order : ", container)
            print()
            if marking_board[depth][num] == 1:
                # print("queen is here", depth, num)
                vis[num] = False
                continue
            mark_board((depth, num))
            vis[num] = True

            container[idx] = board[depth][num]

            permutation_board(idx + 1, depth + 1)
            vis[num] = False


permutation_board(0, 0)

exit()


def mark_board(permu):
    dx = (1, 1,)
    dy = (1, -1,)

    for grid_point in permu:
        for _ in range(2):
            # print(grid_point[0], dx[_])
            x = grid_point[0] + dx[_]
            y = grid_point[1] + dy[_]

            while x < N and y < N:
                if (x, y) in permu:

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

    result = mark_board(permu)
    if not result:
        continue
    else:
        answer += 1

sys.stdout.write(f"{answer}")
