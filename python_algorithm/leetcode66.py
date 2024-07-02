class Solution:
    def plusOne(self, digits):
        _sum = 0
        carry = 1
        loop_index = len(digits) - 1
        while loop_index >= 0 or carry:
            _sum = digits[loop_index] + carry
            if _sum > 9:
                carry = 1
                digits[loop_index] = 0
                return
            else:
                if loop_index == -1:
                    digits.insert(0, _sum)
                    break
                digits[loop_index] = _sum
                carry = 0
            loop_index -= 1
        return digits