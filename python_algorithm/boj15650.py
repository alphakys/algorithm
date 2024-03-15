import sys

from itertools import permutations, combinations

p = permutations(range(1,4), 2)

c = combinations(range(1,4), 2)
print(list(c))

exit()
N, M = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

container = [0] * M
vis = [False] * (N + 1)


def combination(idx, start_num):
    if idx == M:
        str = ''
        for n in container:
            str += f"{n} "

        sys.stdout.write(f"{str}\n")
        return

    for num in range(start_num, N + 1):

        container[idx] = num
        combination(idx + 1, num + 1)



combination(0, 1)

# 4C2 = 3P2// 2! factorial!
# 순열 nPr -> 순서가 있는 배열.

# 순열은 왠지 모르게 쉽다?!
# 하지만 조합은 어려워!

# n (n -1) (n -2) - - - - (n - r + 1)
# 피자의 토핑을 순서대로 넣진 않잖아


# 순열은 순! 열 순서가 있는 배열
# 팩토리얼의 개념이 들어간다. -> 곱의 법칙

# 조합은 순서를 고려하지 마라.

# 순열은 그냥 뽑아 그리고 얘들을 줄세워
# 두 가지의 연산이 들어간다. 여기서 그냥 뽑아가 조합이다.
# 그러면 순열의 두 가지 연산에서 줄 세우기를 취소하면 조합이 된다.
