import sys

N, M = sys.stdin.readline().split(' ')
N, M = int(N), int(M)

grid = []
vis = []
for _ in range(N):
    row = sys.stdin.readline().rstrip().split(' ')
    grid.append([int(n) for n in row])
    vis.append([False] * M)

from collections import deque

q = deque()

dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

cnt_arr = []

for i in range(N):
    for j in range(M):

        if grid[i][j] == 1 and vis[i][j] is False:
            vis[i][j] = True
            q.append((i, j))

            cnt = 1
            while len(q):
                curr = q.popleft()

                for d in dirs:
                    if (d[0] == 0 and (0 <= curr[1]+d[1] < M)) or (d[1] == 0 and (0 <= curr[0]+d[0] < N)):
                        x, y = curr[0] + d[0], curr[1] + d[1]
                    else:
                        continue

                    if grid[x][y] == 1 and vis[x][y] is False:

                        vis[x][y] = True
                        q.append((x, y))
                        cnt += 1
            cnt_arr.append(cnt)


if cnt_arr == []:
    sys.stdout.write(f"0\n0")
else:
    sys.stdout.write(f"{len(cnt_arr)}\n{max(cnt_arr)}")