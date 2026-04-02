from typing import List, Optional
from shared.python.data_structures import ListNode


class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        length = 0
        cur = head
        while cur:
            length += 1
            cur = cur.next
        width, extra = divmod(length, k)
        result = []
        cur = head
        for i in range(k):
            dummy = ListNode(0)
            write = dummy
            size = width + (1 if i < extra else 0)
            for _ in range(size):
                write.next = ListNode(cur.val)
                write = write.next
                cur = cur.next
            result.append(dummy.next)
        return result
