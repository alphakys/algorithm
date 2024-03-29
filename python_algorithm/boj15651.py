import sys

N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

container = [0] * M
vis = [False] * (N + 1)
cnt = [0] * (N + 1)


def duplicate_permutation(idx):
    if idx == M:
        str = ''
        for n in container:
            str += f"{n} "

        sys.stdout.write(f"{str}\n")
        return

    for num in range(1, N + 1):

        if not vis[num]:
            container[idx] = num
            duplicate_permutation(idx + 1)


duplicate_permutation(0)
