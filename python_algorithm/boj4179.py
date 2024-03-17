import copy
import sys
from collections import deque

R, C = map(int, sys.stdin.readline().rstrip().split(' '))

# if R == 1 and C == 1:
#     sys.stdout.write(f"IMPOSSIBLE")
#     exit()

maze = []
visited = []
dist = []
for _ in range(R):
    row = sys.stdin.readline().rstrip()
    maze.append(row)
    visited.append([False] * C)
    dist.append([0] * C)

fv = copy.deepcopy(visited)
fd = copy.deepcopy(dist)

jinwoo_queue = deque()
fire_list = deque()

for i in range(R):
    for j in range(C):
        if maze[i][j] == 'F':
            fire_list.append((i, j))
            fv[i][j] = True
            fd[i][j] = 1
        elif maze[i][j] == 'J':
            visited[i][j] = True
            jinwoo_queue.append((i, j))
            dist[i][j] = 1
delta = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def bfs(q, distance, vis):
    while len(q):
        curr = q.popleft()
        curr_distance = distance[curr[0]][curr[1]]

        for dx, dy in delta:

            x = curr[0] + dx
            y = curr[1] + dy

            if 0 <= x < R and 0 <= y < C and maze[x][y] == '.' \
                    and not vis[x][y]:
                vis[x][y] = True
                distance[x][y] = curr_distance + 1
                q.append((x, y))


bfs(fire_list, fd, fv)
bfs(jinwoo_queue, dist, visited)

f_edge = []
j_edge = []

f_min = 1000000
j_min = 1000000

# 같은 좌표를 비교할 때
# 1. j dis >= 1 and f dis == 0:
# j dis <- min 먹어
# 2. j dis >= 1 and f dis >= 1:
# 비교해야함. if j dis < f dis: min 먹어
# 3.

for r in range(R):
    for c in range(C):
        x, y = -1, -1
        if maze[r][c] not in ['#', 'F']:

            if r == 0 or r == R - 1:
                x = r
                y = c
            else:
                if c == 0 or c == C - 1:
                    x = r
                    y = c
        if x >= 0:
            if maze[x][y] == 'J':
                j_min = 1
                break
            if dist[x][y] >= 1:
                if (fd[x][y] >= 1 and dist[x][y] < fd[x][y]) and j_min > dist[x][y]:
                    j_min = dist[x][y]
                elif fd[x][y] == 0 and j_min > dist[x][y]:
                    j_min = dist[x][y]

if j_min == 1000000:
    sys.stdout.write(f"IMPOSSIBLE")
else:
    sys.stdout.write(f"{j_min}")
