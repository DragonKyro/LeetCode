from typing import List


class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        curr = list(range(1, 10))
        for _ in range(n - 1):
            nxt: List[int] = []
            for num in curr:
                last = num % 10
                if last + k <= 9:
                    nxt.append(num * 10 + last + k)
                if k != 0 and last - k >= 0:
                    nxt.append(num * 10 + last - k)
            curr = nxt
        return curr
