import sys

N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

vis = [False] * (N + 1)
container = [0] * M


# What is == operator
# To compare objects based on their values, Python's equality operator are employed.
# It calls the left object's __eq__() class method. which specifies the criteria for
# determining equality.


def back_tracking(idx):
    if idx == M:
        print("flush : ", container)
        print()
        return

    # for loop가 돌지만 결국 visited가 loop의 길라잡이가 된다.
    for num in range(1, N + 1):
        print("list index : ", idx)
        if not vis[num]:
            print("current unvisited : ", idx)
            print(f"current num : {num}")
            container[idx] = num
            vis[num] = True
            print(container)
            print()
            back_tracking(idx + 1)
            vis[num] = False


# 4, 2

back_tracking(0)






back_tracking(2)
back_tracking(1)
back_tracking(0)