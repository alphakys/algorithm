import sys
from collections import deque

N, M = map(int, sys.stdin.readline().rstrip().split(' '))

board = []

for _ in range(N):
    row = sys.stdin.readline().rstrip().split(' ')
    board.append([int(chr) for chr in row])

dx = (0, 1, 0, -1)
dy = (1, 0, -1, 0)

visited = [[False] * M for _ in range(N)]

qu = deque()

max_val = 0
length = 0
for i in range(N):
    for j in range(M):
        if not visited[i][j] and board[i][j] == 1:

            qu.append((i, j))
            cnt = 0
            while len(qu):

                curr = qu.popleft()
                visited[curr[0]][curr[1]] = True

                cnt += 1
                for k in range(4):
                    x = curr[0] + dx[k]
                    y = curr[1] + dy[k]

                    if 0 <= x < N and 0 <= y < M and board[x][y] == 1 \
                            and not visited[x][y]:
                        visited[x][y] = True
                        qu.append((x, y))

            if max_val < cnt:
                max_val = cnt
            length += 1

sys.stdout.write(f"{length}\n{max_val}")
