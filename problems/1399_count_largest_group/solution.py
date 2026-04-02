class Solution:
    def countLargestGroup(self, n: int) -> int:
        from collections import Counter
        groups = Counter(sum(int(d) for d in str(i)) for i in range(1, n + 1))
        max_size = max(groups.values())
        return sum(1 for v in groups.values() if v == max_size)
