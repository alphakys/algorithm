import itertools

from collections import deque


def solution(queries):
    gens = [[] for _ in range(16)]

    gens[0] = ["Rr"]
    max_generation = max([q[0] for q in queries])
    q = deque(["Rr"])
    gen = 1
    depth_checker = deque()
    while True:
        if gen == max_generation:
            break

        while len(q) > 0:
            depth_checker.append(q.popleft())

        while len(depth_checker) > 0:
            prod = [sorted(list(l)) for l in list(itertools.product(depth_checker.popleft(), repeat=2))]
            for polli in prod:
                q.append(polli)
                gens[gen].append(polli)
        gen += 1

    answer = list(map(lambda x: ''.join(gens[x[0] - 1][x[1] - 1]), queries))
    return answer


queries = [[4, 26]]
queries = [[16, 1], [16, 3], [16, 29]]
# queries = [[3, 5]]
solution(queries)
