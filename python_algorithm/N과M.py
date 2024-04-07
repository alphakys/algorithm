import sys

# N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

N, M = 4, 2

vis = [False] * (N + 1)
container = [0] * M

def permutation(idx):

    if idx == M:
        print(*container)
        return

    for i in range(1, N + 1):
        if not vis[i]:
            container[idx] = i
            permutation(idx + 1)

permutation(0)

























#
# container = [0] * M
# vis = [False] * (N + 1)
#
#
# def back_track(idx):
#     if idx == M:
#         str = ''
#         for n in container:
#             str += f"{n} "
#
#         sys.stdout.write(f"{str}\n")
#         return
#
#     for num in range(1, N + 1):
#
#         if not vis[num]:
#             vis[num] = True
#             container[idx] = num
#             back_track(idx + 1)
#             vis[num] = False
#
#
# back_track(0)
