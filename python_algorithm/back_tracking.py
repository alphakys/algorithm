# 한정 조건!!!!

class Node:

    def __init__(self, v: int):
        self.child_node = []
        self.val: int = v


li = [[1, 5, 3], [2, 4, 7], [9, 3, 5]]

# 재귀는 종결 조건을 잘 짜야한다.

min_val = min(li[0])

print(min_val)

min_arr = []

visited = [1, 0, 0]


def back_tracking(l: list):
    i = 0
    m = 0
    while i < 3:

        if visited[i]:
            i += 1
            continue

        if m > l[i]:
            m = l[i]

        i += 1


exit()