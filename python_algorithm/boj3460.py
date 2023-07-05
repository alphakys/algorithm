import sys

T = int(sys.stdin.readline())

for i in range(T):
    n = int(sys.stdin.readline())
    l = []
    while n > 1:
        l.append(n % 2)
        n = int(n / 2)

    l.append(1)
    print(*[idx for idx, n in enumerate(l) if n > 0])
