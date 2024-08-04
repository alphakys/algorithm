from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        difference_dict = {}
        answer = [0] * 2
        for idx, n in enumerate(nums):
            difference = target - n
            if difference in difference_dict:
                answer[0] = difference_dict[difference]
                answer[1] = idx
                break
            else:
                difference_dict[n] = idx



if __name__ == '__main__':
    nums = [3,2,4]
    target = 6

    Solution().twosum(nums, target)