from typing import Optional
from shared.python.data_structures import ListNode


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        prev = dummy
        while True:
            kth = prev
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next
            nxt = kth.next
            curr = prev.next
            for _ in range(k - 1):
                tmp = curr.next
                curr.next = tmp.next
                tmp.next = prev.next
                prev.next = tmp
            prev = curr
        return dummy.next
