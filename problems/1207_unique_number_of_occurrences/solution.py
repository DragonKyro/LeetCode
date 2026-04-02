class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        from collections import Counter
        cnt = Counter(arr)
        return len(cnt.values()) == len(set(cnt.values()))
