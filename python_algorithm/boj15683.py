import sys

# N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

N, M = 4, 6

# office = []
# for _ in range(N):
#     row = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))
#     office.append(row)

office = [
    [0, 1, 0, 0, 0, 0],
    [0, 0, 2, 0, 0, 0],
    [0, 0, 0, 0, 6, 0],
    [0, 0, 2, 0, 0, 0],
]


class Cctv:
    LIMIT_X = N
    LIMIT_Y = M

    def __init__(self, x, y):
        self.x = x
        self.y = y
        Cctv.LIMIT_X = N
        Cctv.LIMIT_Y = M

    def fetch_left_side(self):
        for i in range(self.y - 1, -1, -1):
            # print(self.x, i)
            if office[self.x][i] == 0:
                office[self.x][i] = '#'

    def fetch_right_side(self):
        for i in range(self.y + 1, Cctv1.LIMIT_Y):
            # print(self.x, i)
            if office[self.x][i] == 0:
                office[self.x][i] = '#'

    def fetch_upper_side(self):
        for i in range(self.x - 1, -1, -1):
            # print(i, self.y)
            if office[i][self.y] == 0:
                office[i][self.y] = '#'

    def fetch_down_side(self):
        for i in range(self.x + 1, Cctv1.LIMIT_X):
            # print(i, self.y)
            if office[i][self.y] == 0:
                office[i][self.y] = '#'

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
        return [(self.fetch_down_side, self.fetch_upper_side, self.fetch_right_side, self.fetch_left_side)]


cctv_list = []

for i in range(N):
    for j in range(M):

        if office[i][j] == 1:
            cctv_list.append(Cctv1(i, j))
        if office[i][j] == 2:
            cctv_list.append(Cctv2(i, j))
        if office[i][j] == 3:
            cctv_list.append(Cctv3(i, j))
        if office[i][j] == 4:
            cctv_list.append(Cctv4(i, j))
        if office[i][j] == 5:
            cctv_list.append(Cctv5(i, j))

# a = [1,2,3]
# b = [4,5,6]
# c = [7,8,9]
#
# arr = [[1,2,3],
#         [4,5,6],
#         [7,8,9]]

print(cctv_list)
method_list = [c.fetch_detect_directions() for c in cctv_list]

vis = []
for m in method_list:
    print(len(m))
    vis.append([False] * len(m))

print(vis)
limit = len(cctv_list)
print(limit)



container = [None] * limit

def permutate_cctv(idx, arr, arr_index):
    if idx == limit:
        print(container)
        return

    for i in range(limit):
        if not vis[arr_index][i]:
            vis[arr_index][i] = True
            container[idx] = arr[arr_index][i]

            permutate_cctv(idx + 1, arr, arr_index+1)
            vis[arr_index][i] = False


permutate_cctv(0, method_list, 0)

exit()
for m in method_list:
    print(m)


print(len(method_list))

def mark_grid(cctv):
    mark_directions = cctv.fetch_detect_directions()

    for fn_list in mark_directions:
        print(fn_list)
        for f in fn_list:
            f()

exit()


limit = len(cctv_list)

# cctv_list = [1,2,3,4,5]
vis = [False] * limit

container = [None] * 5


def permutate_cctv(idx):
    if idx == limit:
        # print(container)
        return

    for i in range(limit):
        if not vis[i]:
            vis[i] = True
            container[idx] = cctv_list[i]
            permutate_cctv(idx + 1)
            vis[i] = False


permutate_cctv(0)



mark_grid(cctv_list[0])

for o in office:
    print(o)

    # [0, 1, 0, 0, 0, 0],
    # [0, 0, 2, 0, 0, 0],
    # [0, 3, 0, 4, 6, 0],
    # [0, 0, 5, 0, 0, 0],
