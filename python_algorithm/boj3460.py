import sys

T = int(sys.stdin.readline())

for i in range(T):
    example = int(sys.stdin.readline())
    answer = []
    while example / 2 > 0:
        answer.append(example % 2)
        example = int(example / 2)

    print(*[idx for idx, n in enumerate(answer) if n > 0])
