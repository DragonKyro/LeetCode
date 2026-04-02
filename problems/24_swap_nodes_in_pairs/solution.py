from typing import Optional
from shared.python.data_structures import ListNode


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        prev = dummy
        while prev.next and prev.next.next:
            a = prev.next
            b = prev.next.next
            prev.next = b
            a.next = b.next
            b.next = a
            prev = a
        return dummy.next
