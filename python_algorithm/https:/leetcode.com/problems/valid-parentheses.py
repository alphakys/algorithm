class Solution:
    def isValid(self, s: str) -> bool:

        open_brackets = ('(', '{', '[')
        close_brackets = (')', '}', ']')

        pair_brackets = zip(open_brackets, close_brackets)
        self.pair_brackets = dict(pair_brackets)

        open_bracket_container = []

        is_valid = None

        for bracket in s:
            if bracket in open_brackets:
                open_bracket_container.append(bracket)
            else:
                is_valid = self.check_valid_close_bracket(open_bracket_container, bracket)
                if is_valid:
                    continue
                else:
                    break

        if not self.is_empty(open_bracket_container):
            return False

        return is_valid

    def is_empty(self, container):
        if container:
            return False

        return True

    def check_valid_close_bracket(self, container: list, close_bracket):

        if not container:
            return False
        else:
            if self.pair_brackets[container[-1]] == close_bracket:
                container.pop(-1)
                return True
            else:
                return False


"""
경우의 수
1. open bracket이 들어온다.
    open bracket을 calling a function의 개념으로 생각하면
    open bracket이 들어올 때마다 open bracket container에 append한다.
2. close bracket이 들어온다.
    2-1. open_bracket_container에 값이 존재한다면
        close bracket과 open_bracket_container의 index -1이(즉 마지막 index의 값이) 같은지를 확인한다.
    2-2. open_bracket_container에 값이 존재하지 않는다면 바로 False
"""

s = Solution()
param = "()"

result = s.isValid(param)

print(result)
