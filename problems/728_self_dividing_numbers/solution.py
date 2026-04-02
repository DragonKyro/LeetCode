from typing import List


class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        result = []
        for num in range(left, right + 1):
            if all(d != '0' and num % int(d) == 0 for d in str(num)):
                result.append(num)
        return result
