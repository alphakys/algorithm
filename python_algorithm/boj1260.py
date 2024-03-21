
def main() -> None:
    import sys
    from collections import deque

    N, M, V = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))

    vis = [False] * (N + 1)

    adj_matrix = [[0] * (N + 1) for i in range(N + 1)]
    for _ in range(M):
        u, v = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))
        adj_matrix[u][v] = 1
        adj_matrix[v][u] = 1

    stack = deque()
    stack.append(V)

    # print(adj_matrix)
    dfs_answer = ''
    while len(stack):

        # 재귀를 통해 구현한 dfs는 pop 할 때 방문 처리를 한다.
        curr = stack.pop()
        if vis[curr]:
            continue

        vis[curr] = True
        dfs_answer += f'{curr} '

        for idx in range(len(adj_matrix) - 1, 0, -1):

            if vis[idx]:
                continue

            if adj_matrix[curr][idx] == 1:
                stack.append(idx)

    print(dfs_answer)

    ####### bfs ******
    vis = [False] * (N + 1)

    stack.append(V)
    vis[V] = True
    bfs_answer = ''
    while len(stack):

        # 재귀를 통해 구현한 dfs는 pop 할 때 방문 처리를 한다.
        curr = stack.popleft()
        # vis[curr] = True
        bfs_answer += f'{curr} '

        for idx, n in enumerate(adj_matrix[curr]):

            if vis[idx]:
                continue

            if n == 1:
                stack.append(idx)
                vis[idx] = True

    print(bfs_answer)


if __name__ == '__main__':
    main()