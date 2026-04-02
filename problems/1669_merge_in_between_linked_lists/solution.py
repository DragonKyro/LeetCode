from shared.python.data_structures import ListNode


class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        prev = list1
        for i in range(a - 1):
            prev = prev.next
        end = prev
        for i in range(b - a + 2):
            end = end.next
        prev.next = list2
        tail = list2
        while tail.next:
            tail = tail.next
        tail.next = end
        return list1
