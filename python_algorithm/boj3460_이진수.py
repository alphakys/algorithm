import sys

T = int(sys.stdin.readline())

for _ in range(T):
    n = int(sys.stdin.readline())

    reminder = []
    while n > 0:
        reminder.append(n % 2)
        n = n // 2
    print(*[i for i, r in enumerate(reminder) if r > 0])