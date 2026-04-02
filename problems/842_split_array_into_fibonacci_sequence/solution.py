from typing import List


class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        def backtrack(idx: int, seq: List[int]) -> bool:
            if idx == len(num):
                return len(seq) >= 3
            for i in range(idx + 1, len(num) + 1):
                if num[idx] == '0' and i > idx + 1:
                    break
                val = int(num[idx:i])
                if val > 2**31 - 1:
                    break
                if len(seq) >= 2:
                    if val > seq[-1] + seq[-2]:
                        break
                    if val < seq[-1] + seq[-2]:
                        continue
                seq.append(val)
                if backtrack(i, seq):
                    return True
                seq.pop()
            return False
        result = []
        backtrack(0, result)
        return result
