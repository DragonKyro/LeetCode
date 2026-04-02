from typing import List


class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sorted_idx = sorted(range(len(score)), key=lambda i: -score[i])
        medals = ['Gold Medal', 'Silver Medal', 'Bronze Medal']
        res = [''] * len(score)
        for rank, idx in enumerate(sorted_idx):
            res[idx] = medals[rank] if rank < 3 else str(rank + 1)
        return res
