class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        times = -(-len(b) // len(a))
        repeated = a * times
        if b in repeated:
            return times
        if b in repeated + a:
            return times + 1
        return -1
