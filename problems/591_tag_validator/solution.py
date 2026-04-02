class Solution:
    def isValid(self, code: str) -> bool:
        import re
        code = re.sub(r'<!\[CDATA\[.*?\]\]>', 'c', code, flags=re.DOTALL)
        prev = ''
        while code != prev:
            prev = code
            code = re.sub(r'<([A-Z]{1,9})>[^<]*</\1>', 't', code)
        return code == 't'
