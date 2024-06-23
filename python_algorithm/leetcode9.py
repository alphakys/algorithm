class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x!=0 and x % 10 == 0):
            return False

        reverse = 0
        while x > reverse:
            reverse = (reverse * 10) + (x % 10)
            x //= 10

        # 파이썬의 bitwise operation은
        # or의 경우 첫번째 인자가 True일 경우 무조건
        # 첫 번째 인자가 return 되고 만약 Fasle 일 경우
        # 두 번째 인자가 무조건 반환된다(따라서 두 번째 인자는 True든 False이든 상관없이 반환됨)

        # 그래서 x가 odd or even number이든 상관없이
        # 짝수일 경우 palindrome일 경우 True 반환
        # 1. Palindrome 맞음 => True
        # 2. 첫 번째 인자 False =>
            # 2-1. Palindrome 이 아니라서 => 두 번째 bitwise operation에서도 어차피 False 반환됨
            # 2-2. 홀수 개수의 숫자라서 => 두 번째 bitwise operation으로 넘어가서
            # 두 번째 bitwise operation에서 True or False 반환
            #
        return x == reverse or x == reverse//10

if __name__ == "__main__":
    answer = Solution().isPalindrome(0)
    print(answer)
