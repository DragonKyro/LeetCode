class Solution:
    def xorQueries(self, arr: list[int], queries: list[list[int]]) -> list[int]:
        n = len(arr)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] ^ arr[i]
        return [prefix[r + 1] ^ prefix[l] for l, r in queries]
