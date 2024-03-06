import pprint
import sys
from collections import deque

N, M = sys.stdin.readline().rstrip().split(' ')

N = int(N)
M = int(M)

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
        dir_list = [self.fetch_down(), self.fetch_right(),
                    self.fetch_up(), self.fetch_left()]

        return [dir for dir in dir_list if dir]

    def __repr__(self):
        return f'x : {str(self.x)}, y : {str(self.y)}'


board = []
visited = []
for i in range(N):
    row = [int(c) for c in sys.stdin.readline().rstrip()]
    board.append(row)
    visited.append([False] * M)

q = deque()

q.append(Grid(0, 0))
visited[0][0] = True

copy_q = deque()

while len(q):
    curr: Grid = q.popleft()

    for node in curr.fetch_dir_list():

        x = node[0]
        y = node[1]
        if node and board[x][y] == 1 \
                and visited[x][y] is False:

            visited[x][y] = True
            q.append(Grid(x, y))

            copy_q.append((x+1, y+1))

pprint.pprint(copy_q)








