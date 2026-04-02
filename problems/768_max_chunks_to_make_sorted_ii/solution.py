from typing import List


class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stack = []
        for num in arr:
            mx = num
            while stack and stack[-1] > num:
                mx = max(mx, stack.pop())
            stack.append(mx)
        return len(stack)
