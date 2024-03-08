import sys
from collections import deque

M, N = sys.stdin.readline().rstrip().split(' ')

M, N = int(M), int(N)

grid = []
vis = []


class Position:
    limit_x = M
    limit_y = N

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def fetch_right(self):
        if self.y + 1 == Position.limit_y:
            return False
        return (self.x, self.y + 1)

    def fetch_left(self):
        if self.y - 1 < 0:
            return False
        return (self.x, self.y - 1)

    def fetch_up(self):
        if self.x - 1 < 0:
            return False
        return (self.x - 1, self.y)

    def fetch_down(self):
        if self.x + 1 == Position.limit_x:
            return False
        return (self.x + 1, self.y)

    def fetch_dir_list(self):
        dir_list = [self.fetch_down(), self.fetch_right(),
                    self.fetch_up(), self.fetch_left()]

        return [dir for dir in dir_list if dir]

    def __repr__(self):
        return f'x : {str(self.x + 1)}, y : {str(self.y + 1)}'


for _ in range(M):
    row = sys.stdin.readline().rstrip()
    grid.append(row)
    vis.append([-1] * N)

q = deque()

for i in range(M):
    for j in range(N):

        if grid[i][j] == 'J' or 'F':
            q.append(Position(i, j))
            vis[i][j] = 0


last_day = 0
while len(q):
    curr: Position = q.popleft()

    positions = curr.fetch_dir_list()

    for p in positions:
        x = p[0]
        y = p[1]

        if vis[x][y] < 0:
            # print("curr : ", curr)
            if grid[x][y] == 0:
                # print("target pos : ", x+1, y+1)
                vis[x][y] = vis[curr.x][curr.y] + 1

                last_day = vis[x][y]
                # print("last : ", last_day)
                # print()
                q.append(Position(x, y))

            elif grid[x][y] == -1:
                vis[x][y] = 0
                [memo.add(p) for p in Position(x, y).fetch_dir_list()]

# for d in vis:
#     print(d)

# grid가 0인데 방문이 안됨 / vis가 -1
# sys.stdout.write(f"{last_day}")


for position in memo:
    if vis[position[0]][position[1]] == -1 and grid[position[0]][position[1]] == 0:
        sys.stdout.write(f"{-1}")
        break
else:
    sys.stdout.write(f"{last_day}")
