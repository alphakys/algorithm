from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        non-decreasging order means every next element isn't less than previous
        non-decreasing order means every next element isn't less than previous
        """
        i = 0
        j = 0
        limit = m + n
        while i < limit:
            if i == m:
                nums1[i:] = nums2[j:]
                break
            elif j == n:
                nums1[m:] = nums2[j:]
                break
            elif nums1[i] > nums2[j]:
                nums1.insert(i, nums2[j])
                i += 1
                j += 1
                m += 1
            elif nums1[i] == nums2[j]:
                nums1.insert(i, nums2[j])
                i += 1
                j += 1
                m += 1
            elif nums1[i] < nums2[j]:
                i += 1
            print(nums1)
        print(nums1)

    def merge_with_sort(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        non-decreasging order means every next element isn't less than previous
        non-decreasing order means every next element isn't less than previous
        """

        for n in nums2:
            nums1[m] = n
            m += 1
        nums1.sort()
        print(nums1)

if __name__ == '__main__':

    nums1 = [1,2]
    m = 2
    nums2 = []
    n = 0
    Solution().merge_with_sort(nums1, m, nums2, n)
