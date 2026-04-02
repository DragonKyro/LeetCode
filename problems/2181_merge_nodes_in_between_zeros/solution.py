from typing import Optional
from shared.python.data_structures import ListNode


class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        curr = dummy
        node = head.next
        total = 0
        while node:
            if node.val == 0:
                curr.next = ListNode(total)
                curr = curr.next
                total = 0
            else:
                total += node.val
            node = node.next
        return dummy.next
