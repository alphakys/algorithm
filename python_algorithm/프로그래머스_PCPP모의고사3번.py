import itertools

from collections import deque


# 00010111

def solution(queries):
    answer = []
    for g, p in queries:
        gen = 4 ** (g - 1)

        while True:
            print(gen, p)
            if gen == 1:
                answer.append("Rr")
                break

            if 1 <= p <= gen // 4:
                answer.append("RR")
                break
            elif gen // 4 < p <= gen // 4 * 3:
                print("sdf")
                gen //= 4
                p = p // 4
            else:
                answer.append("rr")
                break
        print("-------")
    print(answer)
    return answer


queries = [[4, 26]]
# queries = [[3, 1], [2, 3], [3, 9]]
# queries = [[3, 7]]
# queries = [[3, 8], [2, 2]]
solution(queries)
