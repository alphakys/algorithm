# A B
# C B
# D B
# C D
# D E
# E F
# G E

# 1 2
# 3 2
# 4 2
# 3 4
# 4 5
# 5 6
# 7 5

degree_cnt = [-1, 0, 3, 0, 1, 2, 1, 0]
trees = [[], [2], [], [2, 4], [2, 5], [6], [], [5]]

from collections import deque


def main() -> None:
    q = deque()

    for idx, cnt in enumerate(degree_cnt[1:]):
        if cnt == 0:
            q.append(idx + 1)

    sorted_arr = list(q)
    print(q)
    while len(q):
        curr = q.popleft()
        # degree_cnt[curr] -= 1

        for vis_node in trees[curr]:
            print("vis", vis_node)
            degree_cnt[vis_node] -= 1

            print("degree ", degree_cnt[vis_node])
            if degree_cnt[vis_node] == 0:
                q.append(vis_node)
                sorted_arr.append(vis_node)

        # print("curr : ", curr)
        # if degree_cnt[curr] == 0:
        #     sorted_arr.append(curr)
        #     q.append(curr)


    print(sorted_arr)
    print([chr(int(c) + 64) for c in sorted_arr])


if __name__ == '__main__':
    main()
