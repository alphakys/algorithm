import itertools
from itertools import combinations

def solution(ability):
    answer = 0

    sports_category = len(ability[0])
    student_cnt = len(ability)

    combination = list(combinations(range(student_cnt), sports_category))

    for _ in combination:
        print(_)
        permutation = list(itertools.permutations(range(student_cnt), sports_category))
        for idx, p in enumerate(permutation):
            print(ability[_[idx]], p)
    m = [map(lambda x: max(ability[x]), c) for c in combination]

    max_val = 0
    for _ in m:
        print(list(_))
    # for _ in m:
    #     v = sum(list(_))
    #
    #     if v > max_val:
    #         max_val = v
    #
    # print(max_val)
    return answer

ability = [[40, 10, 10], [20, 5, 0], [30, 30, 30], [70, 0, 70], [100, 100, 100]]
solution(ability)
