import sys

N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

container = [0] * M
vis = [False] * (N + 1)

isused = [False] * (N + 1)


def back_track(idx):
    if idx == M:
        str = ''
        for n in container:
            str += f"{n} "

        sys.stdout.write(f"{str}\n")
        return

    for _ in range(1, N+1):

        for num in range(1, N + 1):
            print(num)
            if not vis[num] and not isused[num]:
                print(vis)
                print(isused)
                vis[num] = True
                container[idx] = num
                back_track(idx + 1)
                vis[num] = False

        # print(_)
        isused[_] = True
        # print(isused)
        # print()
        # print("start : ", start_num)


back_track(0)
