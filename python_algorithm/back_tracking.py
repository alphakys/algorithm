import sys

# N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))


nums = [1, 2, 3, 4, 5]
vis = [False] * 6

container = [0] * 5
limit = 5

def back_tracking(idx):

    if idx == limit:
        print(container)
        return

    for num in range(1, 6):

        if not vis[num]:
            vis[num] = True
            container[idx] = num
            print("num : ", num, " vis : ", vis)
            back_tracking(idx + 1)
            vis[num] = False
            print(f"down num{num} /  vis : ", vis)

back_tracking(0)





exit()
































N, M = 4, 4

vis = [False] * (N + 1)
container = [0] * N


def back_track(idx):
    if idx == M:
        print(container)
        return

    print("idx ", idx)
    for num in range(1, N + 1):

        # print("multiverse : ", num)
        # print(vis)
        if not vis[num]:
            vis[num] = True
            container[idx] = num
            back_track(idx + 1)
            vis[num] = False

        print(vis)


back_track(0)
