class Solution:
    def compressedString(self, word: str) -> str:
        res = []
        i = 0
        while i < len(word):
            c = word[i]
            cnt = 0
            while i < len(word) and word[i] == c and cnt < 9:
                cnt += 1
                i += 1
            res.append(str(cnt) + c)
        return ''.join(res)
