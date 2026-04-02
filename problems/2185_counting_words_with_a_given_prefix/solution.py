class Solution:
    def prefixCount(self, words: list[str], pref: str) -> int:
        return sum(1 for w in words if w.startswith(pref))
