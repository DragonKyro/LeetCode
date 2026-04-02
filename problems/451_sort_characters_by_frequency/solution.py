class Solution:
    def frequencySort(self, s: str) -> str:
        from collections import Counter
        count = Counter(s)
        return ''.join(c * freq for c, freq in count.most_common())
