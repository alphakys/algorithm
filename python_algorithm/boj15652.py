import sys

N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

vis = [False] * (N + 1)
container = [0] * M


def permutation(idx, depth):
    if idx == M:
        print(*container)
        return

    for i in range(depth, N + 1):
        container[idx] = i
        permutation(idx + 1, i)


permutation(0, 1)
