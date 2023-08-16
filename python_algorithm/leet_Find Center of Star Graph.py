from collections import defaultdict
from typing import List
class Solution:

    def findCenter(self, edges: List[List[int]]) -> int:

        count_dict = defaultdict(int)
        answer = None
        for ed in edges:
            for num in ed:
                count_dict[num] += 1
                if count_dict[num] > 1:
                    answer = num
                    break
        return answer

