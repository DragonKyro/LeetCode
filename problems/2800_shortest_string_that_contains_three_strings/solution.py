class Solution:
    def minimumString(self, a: str, b: str, c: str) -> str:
        from itertools import permutations
        def merge(s1: str, s2: str) -> str:
            if s2 in s1: return s1
            for i in range(len(s1)):
                if s2.startswith(s1[i:]):
                    return s1[:i] + s2
            return s1 + s2
        best = None
        for p in permutations([a, b, c]):
            res = merge(merge(p[0], p[1]), p[2])
            if best is None or len(res) < len(best) or (len(res) == len(best) and res < best):
                best = res
        return best
