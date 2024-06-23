class Solution:
    def longestCommonPrefix(self, strs: list) -> str:
        strs.sort()
        # alphabetically sorting 하게 되면
        # 처음과 끝의 문자열만 비교하면 된다.
        # 이유는 중간의 문자열들은 끝의 문자열의 순서와 같거나 작을 것이기 때문에
        # 모두 비교할 필요가 없다.
        i = 0
        while (strs[0][i:i+1] and strs[-1][i:i+1]) and strs[0][i:i+1] == strs[-1][i:i+1]:
            i += 1
        return strs[0][:i] # if strs[0][:i] else ""


if __name__ == "__main__":
    strs = [""]
    # print(type(strs[0][2:3]))
    answer = Solution().longestCommonPrefix(strs)
    print(answer)
