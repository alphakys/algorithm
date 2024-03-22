import sys
from collections import deque
from io import StringIO


def main() -> None:
    N = int(sys.stdin.readline().rstrip())

    trees = [[] for _ in range(N + 1)]
    vis = [False] * (N + 1)

    for _ in range(N - 1):
        u, v = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))
        trees[u].append(v)
        trees[v].append(u)

    q = deque()

    q.append(1)
    parent_tree = [None] * (N + 1)
    while len(q):

        curr = q.popleft()
        if vis[curr]:
            continue

        vis[curr] = True

        for n in trees[curr]:

            if vis[n]:
                continue
            q.append(n)
            parent_tree[n] = curr

    io = StringIO()
    for p in parent_tree[2:]:
        io.write(f'{p}\n')
    sys.stdout.write(io.getvalue())

if __name__ == '__main__':
    main()
