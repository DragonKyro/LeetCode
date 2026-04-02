class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        pos = [x for x in nums if x > 0]
        neg = [x for x in nums if x < 0]
        result: list[int] = []
        for i in range(len(pos)):
            result.append(pos[i])
            result.append(neg[i])
        return result
