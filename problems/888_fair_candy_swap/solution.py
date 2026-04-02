from typing import List


class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        sa, sb = sum(aliceSizes), sum(bobSizes)
        diff = (sb - sa) // 2
        bob_set = set(bobSizes)
        for a in aliceSizes:
            if a + diff in bob_set:
                return [a, a + diff]
        return []
