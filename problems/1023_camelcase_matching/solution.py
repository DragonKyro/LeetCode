class Solution:
    def camelMatch(self, queries: list[str], pattern: str) -> list[bool]:
        def matches(query: str, pattern: str) -> bool:
            j = 0
            for c in query:
                if j < len(pattern) and c == pattern[j]:
                    j += 1
                elif c.isupper():
                    return False
            return j == len(pattern)
        return [matches(q, pattern) for q in queries]
