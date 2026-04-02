from shared.python.data_structures import ListNode


class Solution:
    def nextLargerNodes(self, head: ListNode) -> list[int]:
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
        ans = [0] * len(vals)
        stack = []
        for i, v in enumerate(vals):
            while stack and vals[stack[-1]] < v:
                ans[stack.pop()] = v
            stack.append(i)
        return ans
