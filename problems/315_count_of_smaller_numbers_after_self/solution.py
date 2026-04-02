class Solution:
    def countSmaller(self, nums: list[int]) -> list[int]:
        res = [0] * len(nums)
        indices = list(range(len(nums)))
        def merge_sort(arr):
            if len(arr) <= 1:
                return arr
            mid = len(arr) // 2
            left = merge_sort(arr[:mid])
            right = merge_sort(arr[mid:])
            merged = []
            i = j = 0
            while i < len(left) and j < len(right):
                if nums[left[i]] <= nums[right[j]]:
                    res[left[i]] += j
                    merged.append(left[i])
                    i += 1
                else:
                    merged.append(right[j])
                    j += 1
            while i < len(left):
                res[left[i]] += j
                merged.append(left[i])
                i += 1
            while j < len(right):
                merged.append(right[j])
                j += 1
            return merged
        merge_sort(indices)
        return res
