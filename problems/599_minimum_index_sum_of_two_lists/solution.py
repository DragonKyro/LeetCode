from typing import List


class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        index_map = {s: i for i, s in enumerate(list1)}
        min_sum = float('inf')
        result = []
        for j, s in enumerate(list2):
            if s in index_map:
                idx_sum = j + index_map[s]
                if idx_sum < min_sum:
                    min_sum = idx_sum
                    result = [s]
                elif idx_sum == min_sum:
                    result.append(s)
        return result
