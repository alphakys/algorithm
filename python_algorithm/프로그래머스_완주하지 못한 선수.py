participant = ["mislav", "stanko", "mislav", "ana"]
completion = ["stanko", "ana", "mislav"]

from collections import Counter


def solution(participant, completion):
    answer = ''

    counter = {}
    set().difference()
    c = Counter(participant)

    print(c.values())

    print(sorted(c, key=lambda x: x[1]))
    for com in completion:
        c[com] -= 1

    print(c.most_common(1)[0][0])
    return c.most_common(1)[0][0]


solution(participant, completion)
