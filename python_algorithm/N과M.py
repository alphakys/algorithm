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
exit()

arr = list(range(1, N + 1))

visited = [False] * N
container = []

recurrsion = 0


def back_track(container, visited):
    global recurrsion
    if recurrsion == 100:
        return

    recurrsion += 1

    # 한정조건 방문하지 않은 노드에 가야함.
    for i, b in enumerate(visited):
        if not b:
            container.append(arr[i])
            visited[i] = True
            break

    # print(f"recurr : {recurrsion}, visited : {visited}")
    if len(container) == M:
        print(container)
        container.pop()
        return visited
    else:
        visited = back_track(container, visited)

        if not all(visited):
            visited = back_track(container, visited)
        else:
            pass

    return visited


j = 0
while j < N:
    container.append(arr[j])
    visited[j] = True

    visited: list = back_track(container, visited)
    visited = [False] * 4
    container.clear()
    print(f"while : {visited}")

    j += 1
    print(j)
