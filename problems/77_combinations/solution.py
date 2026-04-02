class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        result: list[list[int]] = []

        def backtrack(start: int, combo: list[int]) -> None:
            if len(combo) == k:
                result.append(combo[:])
                return
            for i in range(start, n + 1):
                combo.append(i)
                backtrack(i + 1, combo)
                combo.pop()

        backtrack(1, [])
        return result
