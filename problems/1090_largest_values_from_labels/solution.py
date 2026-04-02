class Solution:
    def largestValsFromLabels(self, values: list[int], labels: list[int], numWanted: int, useLimit: int) -> int:
        from collections import Counter
        pairs = sorted(zip(values, labels), reverse=True)
        label_count = Counter()
        ans = 0
        count = 0
        for val, label in pairs:
            if count >= numWanted:
                break
            if label_count[label] < useLimit:
                ans += val
                label_count[label] += 1
                count += 1
        return ans
