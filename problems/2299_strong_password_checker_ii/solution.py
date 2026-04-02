class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        has_lower = has_upper = has_digit = has_special = False
        special = set('!@#$%^&*()-+')
        for i, c in enumerate(password):
            if c.islower(): has_lower = True
            if c.isupper(): has_upper = True
            if c.isdigit(): has_digit = True
            if c in special: has_special = True
            if i > 0 and c == password[i-1]: return False
        return has_lower and has_upper and has_digit and has_special
