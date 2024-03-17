import sys
from collections import deque

N, M = map(int, sys.stdin.readline().rstrip().split(' '))

board = []

for _ in range(N):
    row = sys.stdin.readline().rstrip()
    board.append([int(chr) for chr in row])

# board = [[1, 0, 1, 1, 1, 1], [1, 0, 1, 0, 1, 0], [1, 0, 1, 0, 1, 1], [1, 1, 1, 0, 1, 1]]
# cnt_board = [[1]*M for _ in range(N)]
# N, M = 4, 6

dx = (0, 1, 0, -1)
dy = (1, 0, -1, 0)

visited = [[False] * M for _ in range(N)]

qu = deque()
qu.append((0, 0))

# queue의 length가 0이 되면 종료 조건

while len(qu):

    curr = qu.popleft()
    curr_val = board[curr[0]][curr[1]]
    visited[curr[0]][curr[1]] = True
    for i in range(4):
        x = curr[0] + dx[i]
        y = curr[1] + dy[i]

        if 0 <= x < N and 0 <= y < M and board[x][y] == 1 \
                and not visited[x][y]:
            board[x][y] = curr_val + 1
            qu.append((x, y))

sys.stdout.write(f"{board[N-1][M-1]}")
