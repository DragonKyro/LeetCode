class Solution:
    def relativeSortArray(self, arr1: list[int], arr2: list[int]) -> list[int]:
        order = {v: i for i, v in enumerate(arr2)}
        return sorted(arr1, key=lambda x: (0, order[x]) if x in order else (1, x))
