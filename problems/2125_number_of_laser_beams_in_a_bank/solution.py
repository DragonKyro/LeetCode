class Solution:
    def numberOfBeams(self, bank: list[str]) -> int:
        prev = 0
        total = 0
        for row in bank:
            count = row.count('1')
            if count > 0:
                total += prev * count
                prev = count
        return total
