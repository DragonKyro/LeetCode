class Solution:
    def countRangeSum(self, nums: list[int], lower: int, upper: int) -> int:
        from sortedcontainers import SortedList
        prefix = [0]
        for num in nums:
            prefix.append(prefix[-1] + num)
        sl = SortedList()
        count = 0
        for s in prefix:
            count += sl.bisect_right(s - lower) - sl.bisect_left(s - upper)
            sl.add(s)
        return count
