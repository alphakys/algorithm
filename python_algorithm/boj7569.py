import sys
from collections import deque

M, N, H = map(int, sys.stdin.readline().rstrip().split(' '))

green_tomato_checker = M * N * H

board = []
for _ in range(H):
    crate = []
    for k in range(N):
        row = sys.stdin.readline().rstrip().split(' ')
        crate.append([int(chr) for chr in row])
    board.append(crate)

delta = [(0, 0, 1), (0, 1, 0), (0, 0, -1), (0, -1, 0), (1, 0, 0), (-1, 0, 0)]
visited = [[[False] * M for _ in range(N)] for _ in range(H)]
distance = [[[0] * M for _ in range(N)] for _ in range(H)]

qu = deque()

for _ in range(H):
    for i in range(N):
        for j in range(M):

            if board[_][i][j] == 1:
                qu.append((_, i, j))
                visited[_][i][j] = True
                green_tomato_checker -= 1
            elif board[_][i][j] == -1:
                green_tomato_checker -= 1

max_distance = 0

while len(qu):

    depth, curr_x, curr_y = qu.popleft()

    visited[depth][curr_x][curr_y] = True

    curr_dist = distance[depth][curr_x][curr_y]
    for dh, dx, dy in delta:
        d = depth + dh
        x = curr_x + dx
        y = curr_y + dy

        if 0 <= x < N and 0 <= y < M and 0 <= d < H and board[d][x][y] == 0 \
                and not visited[d][x][y]:
            green_tomato_checker -= 1
            visited[d][x][y] = True
            qu.append((d, x, y))
            distance[d][x][y] = curr_dist + 1
            max_distance = curr_dist + 1

if green_tomato_checker != 0:
    answer = -1
else:
    answer = max_distance
sys.stdout.write(f"{answer}")
