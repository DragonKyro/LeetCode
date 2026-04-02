from typing import Optional
from shared.python.data_structures import ListNode


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        prev = None
        while slow:
            nxt = slow.next
            slow.next = prev
            prev = slow
            slow = nxt
        while prev:
            if head.val != prev.val:
                return False
            head = head.next
            prev = prev.next
        return True
