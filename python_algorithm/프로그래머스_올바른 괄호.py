
from collections import deque
def solution(s):
    answer = True

    if s[0] == ')':
        return False

    stack = deque()
    stack.append(s[0])

    for bracket in s[1:]:
        if bracket == ')':
            try:
                stack.pop()
            except IndexError:
                return False
        else:
            stack.append(bracket)

    return len(stack) == 0

def main() -> None:
    s = "()()"
    s = "(())()"
    # s = ")()("
    s = "(()("
    solution(s)

if __name__ == '__main__':
    main()
