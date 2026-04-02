class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def build(st: str) -> str:
            result = []
            for c in st:
                if c == '#':
                    if result:
                        result.pop()
                else:
                    result.append(c)
            return ''.join(result)
        return build(s) == build(t)
