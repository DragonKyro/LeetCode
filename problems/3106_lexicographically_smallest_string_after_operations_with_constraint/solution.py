class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        res = list(s)
        for i in range(len(res)):
            dist = min(ord(res[i]) - ord('a'), ord('z') - ord(res[i]) + 1)
            if dist <= k:
                res[i] = 'a'
                k -= dist
            else:
                res[i] = chr(ord(res[i]) - k)
                k = 0
        return ''.join(res)
