import sys
def combination(idx, depth, N, M, container, vis):
    if idx == M:
        print(*container)
        return

    for n in range(depth + 1, N + 1):
        if not vis[n]:
            container[idx] = n
            vis[n] = True
            combination(idx + 1, n, N, M, container, vis)
            vis[n] = False

def main() -> None:
    N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

    combination(0, 0, N, M, [0] * M, [False] * (N + 1))


if __name__ == '__main__':
    main()
