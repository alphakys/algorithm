import sys


def main() -> None:
    K, N = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))
    wires = [0] * K
    for _ in range(K):
        wires[_] = int(sys.stdin.readline().rstrip())

    # 186               200 => upper bound - 1
    # [11, 11, 11, ..., 11]
    # 186 ~ 200
    # print([l//186 for l in lan])

    start = 0
    end = sum(wires) // N + 1
    mid = (start + end) // 2

    # 231 보다 작거나 같으면 11개 이상의 랜선이 만들어진다.
    # [9, 10, 11, 11, 11, 13]

    while start < end:
        wires_sub = [w // mid for w in wires]
        if sum(wires_sub) >= N:

            start = mid + 1
        else:
            end = mid

        mid = (start + end) // 2

    print(start - 1)


if __name__ == '__main__':
    main()
