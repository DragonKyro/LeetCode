from typing import Optional
from shared.python.data_structures import ListNode


class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        first = head
        for _ in range(k - 1):
            first = first.next
        node1 = first
        second = head
        while first.next:
            first = first.next
            second = second.next
        node1.val, second.val = second.val, node1.val
        return head
