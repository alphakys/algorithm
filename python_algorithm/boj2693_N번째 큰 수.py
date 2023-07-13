import sys

N = int(sys.stdin.readline())

for _ in range(N):
    arr = sorted([int(n) for n in sys.stdin.readline().split()])

    print(arr[-3])
