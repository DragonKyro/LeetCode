class Solution:
    def numEquivDominoPairs(self, dominoes: list[list[int]]) -> int:
        count = {}
        result = 0
        for a, b in dominoes:
            key = (min(a, b), max(a, b))
            result += count.get(key, 0)
            count[key] = count.get(key, 0) + 1
        return result
