class Solution:
    def countValidWords(self, sentence: str) -> int:
        def isValid(token: str) -> bool:
            hyphen = 0
            for i, c in enumerate(token):
                if c.isdigit():
                    return False
                if c == '-':
                    hyphen += 1
                    if hyphen > 1:
                        return False
                    if i == 0 or i == len(token) - 1:
                        return False
                    if not token[i - 1].isalpha() or not token[i + 1].isalpha():
                        return False
                if c in '!.,;':
                    if i != len(token) - 1:
                        return False
            return len(token) > 0
        return sum(isValid(t) for t in sentence.split())
