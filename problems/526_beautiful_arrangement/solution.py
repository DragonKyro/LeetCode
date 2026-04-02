class Solution:
    def countArrangement(self, n: int) -> int:
        def backtrack(pos: int, visited: int) -> int:
            if pos > n:
                return 1
            count = 0
            for i in range(1, n + 1):
                if not (visited & (1 << i)) and (i % pos == 0 or pos % i == 0):
                    count += backtrack(pos + 1, visited | (1 << i))
            return count
        return backtrack(1, 0)
