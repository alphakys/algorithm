import sys

N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

# 백트래킹
# 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘
# 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘
# 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘
# 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘

# bfs는 insert 순서대로 순회한다. -> 골고루 퍼져나감.
# dfs는 Last Input을 먼저 순회한다. -> 깊게 파고 들어감.

vis = [False] * (N+1)
container = [0] * N

def recurrsion(num):

    if num == M:
        print(container)
        return

    for i in range(1, N+1):

        if vis[i] is False:
            container[num] = i
            vis[i] = True
            recurrsion(num+1)
            vis[i] = False

recurrsion(0)