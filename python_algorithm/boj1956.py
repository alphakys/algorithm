import sys

from collections import deque

N, M = sys.stdin.readline().split(' ')

N = int(N)
M = int(M)

board = []
for i in range(int(N)):
    row = sys.stdin.readline().rstrip().split(' ')
    row = [int(r) for r in row]
    board.append(row)

q = deque()


class Grid:
    limit_x = N
    limit_y = M

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def fetch_right(self):
        if self.y + 1 == Grid.limit_y:
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
        if self.x + 1 == Grid.limit_x:
            return False
        return (self.x + 1, self.y)

    def fetch_dir_list(self):
        return [self.fetch_up(), self.fetch_right(), self.fetch_left(), self.fetch_down()]

    def __repr__(self):
        return f'x : {str(self.x)}, y : {str(self.y)}'


visited = [[False] * M for i in range(N)]

pivot_arr = []

for i in range(N):
    for j in range(M):
        if not visited[i][j] and board[i][j] == 1:

            q.append(Grid(i, j))
            visited[i][j] = True

            pivot = 0
            while len(q):

                curr: Grid = q.popleft()

                grids = curr.fetch_dir_list()

                for node in grids:
                    if node and board[node[0]][node[1]] == 1 \
                            and visited[node[0]][node[1]] is False:
                        g = Grid(node[0], node[1])
                        q.append(g)
                        visited[node[0]][node[1]] = True
                pivot += 1

            pivot_arr.append(pivot)

if not pivot_arr:
    sys.stdout.write(f"0\n0")
else:
    sys.stdout.write(f"{len(pivot_arr)}\n{max(pivot_arr)}")