from typing import Optional
from shared.python.data_structures import ListNode


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head
        length = 1
        tail = head
        while tail.next:
            tail = tail.next
            length += 1
        k %= length
        if k == 0:
            return head
        tail.next = head
        steps = length - k
        curr = head
        for _ in range(steps - 1):
            curr = curr.next
        new_head = curr.next
        curr.next = None
        return new_head
