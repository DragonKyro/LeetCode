class Solution:
    def findOriginalArray(self, changed: list[int]) -> list[int]:
        if len(changed) % 2 != 0:
            return []
        changed.sort()
        freq: dict[int, int] = {}
        for num in changed:
            freq[num] = freq.get(num, 0) + 1
        result: list[int] = []
        for num in changed:
            if freq.get(num, 0) == 0:
                continue
            if freq.get(num * 2, 0) == 0:
                return []
            result.append(num)
            freq[num] -= 1
            freq[num * 2] -= 1
        return result
