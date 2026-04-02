from typing import List


class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        remainder = [0] * k
        for n in arr:
            remainder[n % k] += 1
        if remainder[0] % 2 != 0:
            return False
        for i in range(1, k // 2 + 1):
            if i == k - i:
                if remainder[i] % 2 != 0:
                    return False
            else:
                if remainder[i] != remainder[k - i]:
                    return False
        return True
