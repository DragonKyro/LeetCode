from typing import List


class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        sa, sb = set(), set()
        ans = []
        count = 0
        for i in range(n):
            sa.add(A[i])
            sb.add(B[i])
            if A[i] in sb: count += 1
            if B[i] in sa and A[i] != B[i]: count += 1
            ans.append(count)
        return ans
