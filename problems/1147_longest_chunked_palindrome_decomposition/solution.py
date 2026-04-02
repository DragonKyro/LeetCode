class Solution:
    def longestDecomposition(self, text: str) -> int:
        n = len(text)
        result = 0
        left = 0
        right = n - 1
        l_str = ''
        r_str = ''
        while left < right:
            l_str += text[left]
            r_str = text[right] + r_str
            if l_str == r_str:
                result += 2
                l_str = ''
                r_str = ''
            left += 1
            right -= 1
        if left == right or l_str:
            result += 1
        return result
