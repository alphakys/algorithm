
from itertools import combinations

def solution(ability):
    answer = 0

    sports_category = len(ability[0])
    student_cnt = len(ability)

    combination = list(combinations(range(student_cnt), sports_category))

    m = [map(lambda x: max(ability[x]), c) for c in combination]

    max_val = 0
    for _ in m:
        v = sum(list(_))

        if v > max_val:
            max_val = v

    print(max_val)
    return answer


solution(ability)
