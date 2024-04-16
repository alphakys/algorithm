# input_string = "edeaaabbccd"
from collections import defaultdict

input_string = "string"
input_string = "ab"


def solution(input_string):
    dict = defaultdict()
    s = set()
    for i, c in enumerate(input_string):
        index = dict.get(c, -1)
        if index >= 0:
            if index == i - 1:
                dict[c] = i
            else:
                s.add(c)
        else:
            dict[c] = i

    s = list(s)
    s = sorted(s)
    answer = ''
    for c in s:
        answer += c

    print("N" if answer == '' else answer)
    return "N" if answer == '' else answer


solution(input_string)
