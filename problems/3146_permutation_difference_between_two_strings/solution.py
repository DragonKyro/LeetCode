class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        pos_s = {c: i for i, c in enumerate(s)}
        pos_t = {c: i for i, c in enumerate(t)}
        return sum(abs(pos_s[c] - pos_t[c]) for c in pos_s)
