

import os

inputs = os.read(0, 10).decode('ascii')

N, M = inputs.split(' ')

N = int(N)
M = int(M)

arr = list(range(1, N+1))

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
