from typing import List


class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda x: (-x[0], x[1]))
        count = 0
        max_def = 0
        for _, d in properties:
            if d < max_def:
                count += 1
            else:
                max_def = d
        return count
