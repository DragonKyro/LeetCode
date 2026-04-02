class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        mx = num
        for d in s:
            if d != '9':
                mx = int(s.replace(d, '9'))
                break
        mn = int(s.replace(s[0], '0'))
        return mx - mn
