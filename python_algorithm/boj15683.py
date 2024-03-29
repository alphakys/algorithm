import sys

N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

# N, M = 4, 6

office = []
vis = [[False] * M for _ in range(N)]

for _ in range(N):
    row = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))
    office.append(row)

total_num = N * M
cctvs = []
for i in range(N):
    for j in range(M):
        if 1 <= office[i][j] <= 5:
            cctvs.append([(i, j), office[i][j]])
            total_num -= 1
        elif office[i][j] == 6:
            total_num -= 1


# 4 6
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 1 0 5 0
# 0 0 0 0 0 0
def tracking(cctv_pos, available_dirs):
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    cnt = 0
    for d in available_dirs:
        cx, cy = cctv_pos
        while True:
            cx += directions[d][0]
            cy += directions[d][1]

            if 0 <= cx < N and 0 <= cy < M:

                if office[cx][cy] == 0 and vis[cx][cy] is False:
                    vis[cx][cy] = True
                    cnt += 1
                elif office[cx][cy] == 6:

                    break
            else:
                break

    return cnt


def reset_mark():
    for i in range(N):
        for j in range(M):
            vis[i][j] = False


def watch_dirs(cctvs):
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    # 0 북 / 1 동 / 2 남 / 3 서
    cctv_available_dirs = [
        [[0], [1], [2], [3]],
        [[0, 2], [1, 3], [0, 2], [1, 3]],
        [[0, 1], [1, 2], [2, 3], [3, 0]],
        [[1, 0, 3], [1, 2, 3], [0, 1, 2], [0, 3, 2]],
        [[0, 1, 2, 3], [0, 1, 2, 3], [0, 2, 3, 1], [2, 3, 0, 1]],
    ]
    min_cnt = 65

    for n in range(4 ** len(cctvs)):

        s = [0] * len(cctvs)
        i = 0
        while True:
            if n == 0:
                break

            s[i] = n % 4
            i += 1
            n = n // 4

        result = 0
        for idx, j in enumerate(s):
            # 2차원 배열에서 0-index => cctv num
            # 2차원 배열에서 1-index => cctv가 감시할 수있는 방향의 경우의 수
            cctv_num = cctvs[idx][1]
            xy_tuple = cctvs[idx][0]

            directions = cctv_available_dirs[cctv_num - 1][j]
            result += tracking(xy_tuple, directions)

        result = total_num - result
        if min_cnt > result:
            min_cnt = result

        reset_mark()
    return min_cnt


answer = watch_dirs(cctvs)

print(answer)
exit()

cctv_list = []
for i in range(N):
    for j in range(M):

        if office[i][j] == 1:
            cctv_list.append((1, i, j))
        elif office[i][j] == 2:
            cctv_list.append((2, i, j))
        elif office[i][j] == 3:
            cctv_list.append((3, i, j))
        elif office[i][j] == 4:
            cctv_list.append((4, i, j))
        elif office[i][j] == 5:
            cctv_list.append((5, i, j))
        # elif office[i][j] == 6:
        #     blocks += 1

# 1번 cctv부터 5번 cctv 까지 각 cctv가 바로볼 수 있는 방향이 다르지만 최대 경우의 수인 4 방향을 모두 볼수 있다고 가정하고.
# cctv 개수 만큼을 row 로 잡고 4개의 경우의 수를 4진법으로 경우의 수를 순열을 돌리고 그에 대한 계산으로 나오는 값을
# dictionary의 key로 둔다?!!

# 2 * 2 * 1
# # 2cctv | 2cctv | 5cctv
#   0         0       0
#   0         1       0
#   1         0       0
#   1         1       0

cctv1 = (0, 1, 2, 3)
cctv2 = (4, 5)
cctv3 = (6, 7, 8, 9)
cctv4 = (0, 1, 2, 3)
cctv5 = (0,)

cctvs = [cctv1, cctv2, cctv3]

rows = 3

container = [0] * rows
visited = [[False] * 4, [False] * 2, [False] * 4]


def permutate_cctv(idx, arr_index):
    if idx == rows:
        print(container)
        return

    for i in range(len(cctvs[arr_index])):

        if not visited[arr_index][i]:
            visited[arr_index][i] = True
            container[idx] = cctvs[arr_index][i]
            permutate_cctv(idx + 1, arr_index + 1)
            visited[arr_index][i] = False


permutate_cctv(0, 0)
exit()

total_row_cnt = 1

rows = len(cctv_list)

for cctv_num in [c[0] for c in cctv_list]:

    if cctv_num == 1:
        total_row_cnt = total_row_cnt * 4
    elif cctv_num == 2:
        total_row_cnt = total_row_cnt * 2
    elif cctv_num == 3:
        total_row_cnt = total_row_cnt * 4
    elif cctv_num == 4:
        total_row_cnt = total_row_cnt * 4
    elif cctv_num == 5:
        total_row_cnt = total_row_cnt * 1

cctv_permutation = [[[0] * rows] * total_row_cnt]
print(cctv_permutation)

exit()


# office = [
#     [0, 0, 0, 0, 0, 0],
#     [0, 0, 0, 0, 0, 0],
#     [0, 0, 1, 0, 6, 0],
#     [0, 0, 0, 0, 0, 0],
# ]


class Cctv:
    LIMIT_X = N
    LIMIT_Y = M

    def __init__(self, x, y):
        self.x = x
        self.y = y
        Cctv.LIMIT_X = N
        Cctv.LIMIT_Y = M

    def fetch_left_side(self):
        grid_x_y = set()
        for i in range(self.y - 1, -1, -1):
            if office[self.x][i] == 0:
                grid_x_y.add((self.x, i))
            elif office[self.x][i] == 6:
                break
        return grid_x_y

    def fetch_right_side(self):
        grid_x_y = set()
        for i in range(self.y + 1, Cctv1.LIMIT_Y):
            if office[self.x][i] == 0:
                grid_x_y.add((self.x, i))
            elif office[self.x][i] == 6:
                break
        return grid_x_y

    def fetch_upper_side(self):
        grid_x_y = set()
        for i in range(self.x - 1, -1, -1):
            if office[i][self.y] == 0:
                grid_x_y.add((i, self.y))
            elif office[i][self.y] == 6:
                break
        return grid_x_y

    def fetch_down_side(self):
        grid_x_y = set()
        for i in range(self.x + 1, Cctv1.LIMIT_X):

            if office[i][self.y] == 0:

                grid_x_y.add((i, self.y))
            elif office[i][self.y] == 6:
                break
        return grid_x_y

    def __repr__(self):
        return f"{self.__class__} / ( x: {self.x}, y : {self.y} )"


class Cctv1(Cctv):
    def fetch_detect_directions(self):
        return [[self.fetch_down_side], [self.fetch_upper_side], [self.fetch_right_side], [self.fetch_left_side]]


class Cctv2(Cctv):
    def fetch_detect_directions(self):
        return [[self.fetch_down_side, self.fetch_upper_side], [self.fetch_right_side, self.fetch_left_side]]


class Cctv3(Cctv):
    def fetch_detect_directions(self):
        return [[self.fetch_down_side, self.fetch_left_side],
                [self.fetch_down_side, self.fetch_right_side],
                [self.fetch_upper_side, self.fetch_left_side],
                [self.fetch_upper_side, self.fetch_right_side]]


class Cctv4(Cctv):
    def fetch_detect_directions(self):
        return [[self.fetch_down_side, self.fetch_left_side, self.fetch_right_side],
                [self.fetch_right_side, self.fetch_upper_side, self.fetch_down_side],
                [self.fetch_upper_side, self.fetch_left_side, self.fetch_right_side],
                [self.fetch_left_side, self.fetch_upper_side, self.fetch_down_side]]


class Cctv5(Cctv):
    def fetch_detect_directions(self):
        return [[self.fetch_down_side, self.fetch_upper_side, self.fetch_right_side, self.fetch_left_side]]


cctv_list = []
blocks = 0
for i in range(N):
    for j in range(M):

        if office[i][j] == 1:
            cctv_list.append(Cctv1(i, j))
        elif office[i][j] == 2:
            cctv_list.append(Cctv2(i, j))
        elif office[i][j] == 3:
            cctv_list.append(Cctv3(i, j))
        elif office[i][j] == 4:
            cctv_list.append(Cctv4(i, j))
        elif office[i][j] == 5:
            cctv_list.append(Cctv5(i, j))
        elif office[i][j] == 6:
            blocks += 1

method_list = [c.fetch_detect_directions() for c in cctv_list]

vis = []
for m in method_list:
    vis.append([False] * len(m))

limit = len(cctv_list)
container = [None] * limit

min = 65


def permutate_cctv(idx, arr, arr_index):
    if idx == limit:
        global min
        result = set()
        for func_list in container:
            for f in func_list:
                result.update(f())

        answer = (N * M) - (len(result) + limit + blocks)
        if min > answer:
            min = answer
        return

    for i in range(len(arr[arr_index])):

        if not vis[arr_index][i]:
            vis[arr_index][i] = True
            container[idx] = arr[arr_index][i]
            permutate_cctv(idx + 1, arr, arr_index + 1)
            vis[arr_index][i] = False


permutate_cctv(0, method_list, 0)

sys.stdout.write(f"{min}")
