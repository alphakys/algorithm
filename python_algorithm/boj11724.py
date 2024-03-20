import sys
from collections import deque


N, M = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))

# if M == 0:
#     print(1)
#     exit()

adj_matrix = [[0] * (N + 1) for i in range(N + 1)]
for _ in range(M):
    n, e = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))
    adj_matrix[n][e] = 1
    adj_matrix[e][n] = 1

vis = [False] * (N + 1)

stack = deque()

connected_component = []
for node in range(1, N + 1):
    s = set()
    for edge in range(1, N + 1):
        if adj_matrix[node][edge] == 1 and not vis[edge]:
            vis[node] = True
            vis[edge] = True
            stack.append(edge)
            s.add(node)

    while len(stack):

        curr_node = stack.pop()
        s.add(curr_node)
        for e in range(1, N + 1):
            if adj_matrix[curr_node][e] == 1 and not vis[e]:
                stack.append(e)
                vis[e] = True

    if s:
        connected_component.append(s)

answer = len(connected_component)

if vis.count(False) > 1:
    answer += vis.count(False) - 1

print(answer)
