from typing import List, Optional
from shared.python.data_structures import ListNode


class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        remove = set(nums)
        dummy = ListNode(0, head)
        curr = dummy
        while curr.next:
            if curr.next.val in remove:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return dummy.next
