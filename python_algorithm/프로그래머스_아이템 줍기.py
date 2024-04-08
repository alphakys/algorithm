rectangle = [[1, 1, 7, 4], [3, 2, 5, 5], [4, 3, 6, 9], [2, 6, 8, 8]]
characterX = 1
characterY = 3
itemX = 7
itemY = 8

from collections import deque


def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0

    limit_x = 10
    limit_y = 10

    grid = [[0] * limit_x for _ in range(limit_x)]
    vis = [[False] * limit_x for _ in range(limit_x)]

    points = [1, 1, 7, 4]

    grid[4 + 1][7 + 1] = 1
    for g in grid:
        print(g)

    exit()
    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    q = deque()
    q.append((8, 1))
    grid[9 - 1][1] = 1
    vis[9 - 1][1] = True

    while len(q) > 0:

        x, y = q.popleft()
        for dx, dy in dirs:
            tx, ty = 9 - x + dx, 9 - y + dy
            if ((tx == points[0] or tx == points[2]) or (ty == points[1] or ty == points[3]))\
                    and (1 <= tx < limit_x and 1 <= ty < limit_y) and not vis[tx][ty]:
                q.append((tx, ty))
                print(tx, ty)
                vis[tx][ty] = True
                grid[tx][ty] = 1

    for g in grid:
        print(g)



    # x 좌표가 1 / 7 인것 순회
    # y 좌표가 1 / 4 인것 순회

    return answer


solution(rectangle, characterX, characterY, itemX, itemY)
