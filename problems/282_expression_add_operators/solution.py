from typing import List


class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        def backtrack(idx, path, value, prev):
            if idx == len(num):
                if value == target:
                    res.append(path)
                return
            for i in range(idx, len(num)):
                if i > idx and num[idx] == '0':
                    break
                curr = int(num[idx:i+1])
                if idx == 0:
                    backtrack(i + 1, str(curr), curr, curr)
                else:
                    backtrack(i + 1, path + '+' + str(curr), value + curr, curr)
                    backtrack(i + 1, path + '-' + str(curr), value - curr, -curr)
                    backtrack(i + 1, path + '*' + str(curr), value - prev + prev * curr, prev * curr)
        backtrack(0, '', 0, 0)
        return res
