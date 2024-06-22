class Solution:
    def isPalindrome(self, x: int) -> bool:
        origin_num = x
        if x < 0:
            return False
        palindrome_num = 0
        while x != 0:
            palindrome_num *= 10
            palindrome_num += (x % 10)
            x //= 10

        return origin_num == palindrome_num


if __name__ == "__main__":
    answer = Solution().isPalindrome(12233221)
    print(answer)
