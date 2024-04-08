import copy
from collections import deque


def solution(maps):
    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    limit_x = len(maps)
    limit_y = len(maps[0])

    map_copy = copy.deepcopy(maps)
    distance = [[-1 for m in maps] for maps in map_copy]

    q = deque()
    q.append((0, 0))
    distance[0][0] = 1

    while len(q) > 0:
        x, y = q.popleft()
        curr_dis = distance[x][y]

        for dx, dy in dirs:
            tx, ty = x + dx, y + dy
            if (0 <= tx < limit_x and 0 <= ty < limit_y) and maps[tx][ty] == 1 \
                    and distance[tx][ty] == -1:
                q.append((tx, ty))
                distance[tx][ty] = curr_dis + 1

    answer = distance[limit_x - 1][limit_y - 1]

    return answer


maps = [[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 1], [0, 0, 0, 0, 1]]

solution(maps)
