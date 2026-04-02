class Solution:
    def maxNumber(self, nums1: list[int], nums2: list[int], k: int) -> list[int]:
        def maxSingle(nums, t):
            drop = len(nums) - t
            stack = []
            for num in nums:
                while drop and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:t]
        def merge(a, b):
            res = []
            while a or b:
                if a >= b:
                    res.append(a[0])
                    a = a[1:]
                else:
                    res.append(b[0])
                    b = b[1:]
            return res
        best = []
        for i in range(max(0, k - len(nums2)), min(k, len(nums1)) + 1):
            candidate = merge(maxSingle(nums1, i), maxSingle(nums2, k - i))
            if candidate > best:
                best = candidate
        return best
