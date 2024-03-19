import sys
from collections import deque

N, M = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))

# if M == 0:
#     print(1)
#     exit()

graph = [[0] * (N + 1) for i in range(N + 1)]
for _ in range(M):
    n, e = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))
    graph[n][e] = 1
    graph[e][n] = 1

for g in graph:
    print(g)

vis = [False] * (N + 1)

stack = deque()
cnt = 0
for node in range(1, N + 1):
    for edge in range(1, N + 1):

        if graph[node][edge] == 1 and not vis[edge]:
            cnt += 1
            vis[node] = True
            vis[edge] = True
            stack.append(edge)

            while len(stack):

                curr_node = stack.pop()
                for e in range(1, N + 1):
                    if graph[curr_node][e] == 1 and not vis[e]:
                        stack.append(e)
                        vis[e] = True

print(vis)
if vis.count(False) > 1:
    cnt += vis.count(False) - 1

print(cnt)
