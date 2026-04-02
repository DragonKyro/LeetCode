from shared.python.data_structures import ListNode


class Solution:
    def getDecimalValue(self, head: 'ListNode') -> int:
        val = 0
        while head:
            val = val * 2 + head.val
            head = head.next
        return val
