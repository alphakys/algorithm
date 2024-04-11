import itertools
import pprint
from itertools import combinations



def solution(ability):
    answer = 0

    sports_category = len(ability[0])  # M
    student_cnt = len(ability)  # N

    com = list(combinations(ability, sports_category))

    per = list(itertools.permutations(range(sports_category), sports_category))

    for c in com:
        for p in per:
            score = 0
            for i in range(len(p)):
                score += c[i][p[i]]

            if score > answer:
                answer = score

    return answer

ability = [[20, 30], [30, 20], [20, 30]]
solution(ability)
