class Solution:
    def isNumber(self, s: str) -> bool:
        import re
        return bool(re.match(r'^[+-]?(\d+\.?\d*|\.\d+)([eE][+-]?\d+)?$', s.strip()))
