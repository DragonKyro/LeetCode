from typing import Optional
from shared.python.data_structures import ListNode


class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        values: list[int] = []
        curr = head
        while curr:
            values.append(curr.val)
            curr = curr.next
        n = len(values)
        return max(values[i] + values[n - 1 - i] for i in range(n // 2))
