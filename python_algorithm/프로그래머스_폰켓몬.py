

nums = [3,1,2,3]
nums =[3,3,3,2,2,4]
# nums = [1, 1, 1, 1]

def solution(nums):

    return min(len(nums) // 2, len(set(nums)))

solution(nums)