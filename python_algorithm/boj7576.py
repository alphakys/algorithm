import sys
from collections import deque

M, N = map(int, sys.stdin.readline().rstrip().split(' '))

green_tomato_checker = N * M

board = []

for _ in range(N):
    row = sys.stdin.readline().rstrip().split(' ')
    board.append([int(chr) for chr in row])

dx = (0, 1, 0, -1)
dy = (1, 0, -1, 0)

visited = [[False] * M for _ in range(N)]
distance = [[0] * M for _ in range(N)]

qu = deque()

for i in range(N):
    for j in range(M):

        if board[i][j] == 1:
            qu.append((i, j))
            visited[i][j] = True
            green_tomato_checker -= 1
        elif board[i][j] == -1:
            green_tomato_checker -= 1

max_distance = 0

while len(qu):

    curr = qu.popleft()

    visited[curr[0]][curr[1]] = True

    curr_dist = distance[curr[0]][curr[1]]
    for k in range(4):
        x = curr[0] + dx[k]
        y = curr[1] + dy[k]

        if 0 <= x < N and 0 <= y < M and board[x][y] == 0 \
                and not visited[x][y]:
            green_tomato_checker -= 1
            visited[x][y] = True
            qu.append((x, y))
            distance[x][y] = curr_dist + 1
            max_distance = curr_dist + 1

for b in distance:

    print(b)

if green_tomato_checker != 0:
    answer = -1
else:
    answer = max_distance
sys.stdout.write(f"{answer}")
