import sys

N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

vis = [False] * (N + 1)
container = [0] * N

# What is == operator
# To compare objects based on their values, Python's equality operator are employed.
# It calls the left object's __eq__() class method. which specifies the criteria for
# determining equality.

def back_tracking(idx):

    if len(container) == M:
        print(container)
        return

    for num in range(1, N+1):

        if not vis[idx]:
            container[idx] = num

# 4, 2

back_tracking(0)