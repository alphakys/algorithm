import sys
from collections import deque

stack = deque()

computers = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]

n = len(computers)

networks = [[] for _ in range(n)]
visited = [False] * n

for i in range(n):
    for j in range(n):

        if computers[i][j] == 1:
            networks[i].append(j)

graphs = [[] for _ in range(n)]

# for loop문은 내부 index가 increment 하는 방식으로 작동한다.
for idx, nodes in enumerate(networks):
    # print(idx, nodes)
    if not visited[idx]:
        visited[idx] = True
        graphs[idx].append(idx)
        for com in nodes:
            if com:

                stack.append(com)
                while len(stack):
                    curr = stack.pop()
                    if not visited[curr]:
                        # 현재 idx = 0에 연결된 / 노드 번호
                        graphs[idx].append(curr)
                        visited[curr] = True
                        [stack.append(n) for n in networks[curr] if not visited[n]]

network_cnt = int(graphs.count([]))
