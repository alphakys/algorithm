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


#
# N = int(N)
# M = int(M)
#
# class Grid:
#     limit_x = N
#     limit_y = M
#
#     def __init__(self, x, y):
#         self.x = x
#         self.y = y
#
#     def fetch_right(self):
#         if self.y + 1 == Grid.limit_y:
#             return False
#         return (self.x, self.y + 1)
#
#     def fetch_left(self):
#         if self.y - 1 < 0:
#             return False
#         return (self.x, self.y - 1)
#
#     def fetch_up(self):
#         if self.x - 1 < 0:
#             return False
#         return (self.x - 1, self.y)
#
#     def fetch_down(self):
#         if self.x + 1 == Grid.limit_x:
#             return False
#         return (self.x + 1, self.y)
#
#     def fetch_dir_list(self):
#         dir_list = [self.fetch_down(), self.fetch_right(),
#                     self.fetch_up(), self.fetch_left()]
#
#         return [dir for dir in dir_list if dir]
#
#     def __repr__(self):
#         return f'x : {str(self.x)}, y : {str(self.y)}'
#
#
# board = []
# visited = []
# distance = []
# for i in range(N):
#     row = [int(c) for c in sys.stdin.readline().rstrip()]
#     board.append(row)
#     visited.append([False] * M)
#     distance.append([0] * M)
#
# q = deque()
#
# q.append(Grid(0, 0))
# visited[0][0] = True
#
# copy_q = deque()
#
# while len(q):
#     curr: Grid = q.popleft()
#
#
#     if (curr.x+1, curr.y+1) == (N, M):
#         copy_q.append((curr.x + 1, curr.y + 1))
#         break
#
#     for node in curr.fetch_dir_list():
#
#         x = node[0]
#         y = node[1]
#         if board[x][y] == 1 \
#                 and visited[x][y] is False:
#
#             visited[x][y] = True
#             q.append(Grid(x, y))
#             curr_dis = distance[curr.x][curr.y]
#             distance[x][y] = curr_dis + 1
#
# for d in distance:
#     print(d)
# sys.stdout.write(f"{distance[N-1][M-1]+1}")
#
#
#
# # 6 6
# # 111111
# # 111111
# # 111111
# # 111111
# # 111111
# # 111111
