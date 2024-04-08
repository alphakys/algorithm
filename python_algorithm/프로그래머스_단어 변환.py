

begin = "hit"
target = "cog"
words = ["hot", "dot", "dog", "lot", "log", "cog"]

def solution(begin, target, words):
    answer = 0

    arr = []
    for w in words:
        # print(w)
        # print([target[i] == w[i] for i in range(len(w))])
        arr.append([target[i] == w[i] for i in range(len(w))])

    for a in arr:
        print(a)

    return answer


solution(begin, target, words)