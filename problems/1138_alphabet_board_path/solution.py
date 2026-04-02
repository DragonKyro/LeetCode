class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        result = []
        r, c = 0, 0
        for ch in target:
            idx = ord(ch) - ord('a')
            tr, tc = idx // 5, idx % 5
            while r > tr:
                result.append('U')
                r -= 1
            while c > tc:
                result.append('L')
                c -= 1
            while r < tr:
                result.append('D')
                r += 1
            while c < tc:
                result.append('R')
                c += 1
            result.append('!')
        return ''.join(result)
