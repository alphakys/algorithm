import sys

# N, r, c = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

N = 8


def divide(N, xy):
    while True:
        if N == 1:
            break

        l = [(0 + xy[0], 0 + xy[1]), (0 + xy[0], N // 2 + xy[1]),
            (N // 2 + xy[0], 0 + xy[1]), (N // 2 + xy[0], N // 2 + xy[1])]

        print(l, N, xy)
        N //= 2
        for p in l:
            divide(N, p)

divide(N, (0, 0))

exit()













delta = [(0, 0), (0, 1),
         (1, 0), (1, 1)]

board = []
# row and colum count
row_col_cnt = 2 ** N
for i in range(row_col_cnt):
    board.append([0] * row_col_cnt)

increment = 0

print("in : ", increment)


def recurrsion(starting_point):
    global increment
    # print(increment)
    for d in delta:
        x, y = d[0] + starting_point[0], d[1] + starting_point[1]

        print(x, y, increment)
        board[x][y] = increment
        increment += 1


def divide(n, starting_point):
    if n == 0:
        return

    # (0, 8)
    # (0,8) (0, 12) (12, 0) (12, 12)

    # (0, 0)
    # st: [(0, 0), (0, 4), (4, 0), (4, 4)]

    positions = [(starting_point[0] + (d[0] * (2 ** n)), starting_point[1] + (d[1] * (2 ** n))) for d in delta]
    print("st : ", positions, n)
    for p in positions:
        result = divide(n - 1, p)
        recurrsion(p)

    return


n = N - 1
positions = [(d[0] * (2 ** n), d[1] * (2 ** n)) for d in delta]

print(positions)
for posi in positions:
    print(posi)
    divide(n - 1, posi)

for b in board:
    print(b)
