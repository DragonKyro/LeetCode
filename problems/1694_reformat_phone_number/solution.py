class Solution:
    def reformatNumber(self, number: str) -> str:
        digits = number.replace(' ', '').replace('-', '')
        groups = []
        i = 0
        while len(digits) - i > 4:
            groups.append(digits[i:i + 3])
            i += 3
        remaining = len(digits) - i
        if remaining <= 3:
            groups.append(digits[i:])
        else:
            groups.append(digits[i:i + 2])
            groups.append(digits[i + 2:])
        return '-'.join(groups)
