class Solution:
    roman_nums = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000,
    }

    def romanToInt(self, s: str) -> int:
        idx = 0
        cnt = len(s)
        answer = 0
        while idx < cnt:
            if idx < cnt-1 and self.roman_nums[s[idx]] < self.roman_nums[s[idx + 1]]:
                answer -= self.roman_nums[s[idx]]
            else:
                answer += self.roman_nums[s[idx]]
            idx += 1

        return answer

if __name__ == "__main__":
    s = "MCMXCIV"
    answer = Solution().romanToInt(s=s)

    print(answer)









# idx = 0
# cnt = len(s)
# answer = 0
# while idx < cnt:
#     char = s[idx]
#     if idx != cnt-1 and char in ["I", "X", "C"]:
#         subtraction_num = self.roman_nums.get(f"{char}{s[idx + 1]}", 0)
#         if subtraction_num:
#             idx += 1
#             answer += subtraction_num
#         else:
#             answer += self.roman_nums[char]
#     else:
#         answer += self.roman_nums[char]
#     idx += 1
# return answer