from typing import List


class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        result = set()
        current = set()
        for x in arr:
            current = {x | y for y in current} | {x}
            result |= current
        return len(result)
