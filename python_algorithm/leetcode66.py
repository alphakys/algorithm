class Solution:
    def plusOne(self, digits):
        loop_idx = len(digits) - 1
        while loop_idx >= 0:
            # 계속해서 9 + 1 = 10 이 되지 않는다면 결국 while statement를 나오게 될 것이다.
            if digits[loop_idx] < 9:
                digits[loop_idx] += 1
                return
            digits[loop_idx] = 0
            loop_idx -= 1
        digits.insert(0, 1)

if __name__ == '__main__':
    digits = [9]
    Solution().plusOne(digits)
    print(digits)