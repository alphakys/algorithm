# input_string = "edeaaabbccd"
input_string = "string"
input_string = "zbzbz"

def solution(input_string):
    counter = [[] for _ in range(26)]
    for i, c in enumerate(input_string):
        counter[int(ord(c)) - 97].append(i)

    answer = []
    for idx, cnt in enumerate(counter):
        if len(cnt) <= 1:
            continue
        i = 0
        while i < len(cnt) - 1:
            if cnt[i + 1] - cnt[i] > 1:
                answer.append(chr(idx+97))
                break
            i += 1
    # print('N' if not answer else ''.join(answer))
    return 'N' if not answer else ''.join(answer)


solution(input_string)
