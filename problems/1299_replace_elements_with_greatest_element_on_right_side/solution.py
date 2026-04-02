class Solution:
    def replaceElements(self, arr: list[int]) -> list[int]:
        max_right = -1
        for i in range(len(arr) - 1, -1, -1):
            new_max = max(max_right, arr[i])
            arr[i] = max_right
            max_right = new_max
        return arr
