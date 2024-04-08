
input_string = "eeddee"

def solution(input_string):
    answer = []
    limit = len(input_string)

    for i, c in enumerate(input_string):
        print(c)
        for _ in range(i + 1, limit):

            if c == input_string[_] and input_string[_] != input_string[_ - 1]:
                answer.append(input_string[_])
    answer.sort()
    str = ''.join(answer)

    return str

solution(input_string)