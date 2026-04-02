class Solution:
    def wiggleSort(self, nums: list[int]) -> None:
        import statistics
        median = statistics.median(nums)
        n = len(nums)
        def idx(i):
            return (1 + 2 * i) % (n | 1)
        i, j, k = 0, 0, n - 1
        while j <= k:
            if nums[idx(j)] > median:
                nums[idx(i)], nums[idx(j)] = nums[idx(j)], nums[idx(i)]
                i += 1
                j += 1
            elif nums[idx(j)] < median:
                nums[idx(j)], nums[idx(k)] = nums[idx(k)], nums[idx(j)]
                k -= 1
            else:
                j += 1
