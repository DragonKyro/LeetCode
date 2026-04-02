class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        result = ['a'] * n
        k -= n
        for i in range(n - 1, -1, -1):
            add = min(25, k)
            result[i] = chr(ord('a') + add)
            k -= add
            if k == 0:
                break
        return ''.join(result)
