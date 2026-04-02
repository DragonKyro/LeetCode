from typing import List


class Solution:
    def validStrings(self, n: int) -> List[str]:
        res = []
        def bt(s):
            if len(s) == n:
                res.append(s)
                return
            bt(s + '1')
            if not s or s[-1] == '1':
                bt(s + '0')
        bt('')
        return res
