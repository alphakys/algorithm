import sys
from collections import deque
from io import StringIO


def main() -> None:
    N, M = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))

    degree_cnt = [0] * (N + 1)
    trees = [[] for _ in range(N + 1)]
    for _ in range(M):
        num1, num2 = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))
        degree_cnt[num2] += 1
        trees[num1].append(num2)

    q = deque()
    for idx, cnt in enumerate(degree_cnt[1:]):
        if cnt == 0:
            q.append(idx + 1)

    sorted_arr = list(q)

    while len(q):
        curr = q.popleft()

        for vis_node in trees[curr]:
            degree_cnt[vis_node] -= 1

            if degree_cnt[vis_node] == 0:
                q.append(vis_node)
                sorted_arr.append(vis_node)

    io = StringIO()
    for p in sorted_arr:
        io.write(f'{p} ')
    sys.stdout.write(io.getvalue())


if __name__ == '__main__':
    main()
