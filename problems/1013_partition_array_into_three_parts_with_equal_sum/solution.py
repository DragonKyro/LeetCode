class Solution:
    def canThreePartsEqualSum(self, arr: list[int]) -> bool:
        total = sum(arr)
        if total % 3 != 0:
            return False
        target = total // 3
        parts = 0
        current = 0
        for i in range(len(arr)):
            current += arr[i]
            if current == target:
                parts += 1
                current = 0
        return parts >= 3
