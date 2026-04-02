class Solution:
    def maximumSum(self, arr: list[int]) -> int:
        n = len(arr)
        no_delete = arr[0]
        one_delete = float('-inf')
        result = arr[0]
        for i in range(1, n):
            one_delete = max(one_delete + arr[i], no_delete)
            no_delete = max(no_delete + arr[i], arr[i])
            result = max(result, no_delete, one_delete)
        return result
