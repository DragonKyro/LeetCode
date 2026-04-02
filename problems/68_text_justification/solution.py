class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        result = []
        line: list[str] = []
        line_len = 0
        for word in words:
            if line_len + len(word) + len(line) > maxWidth:
                for i in range(maxWidth - line_len):
                    line[i % (len(line) - 1 or 1)] += ' '
                result.append(''.join(line))
                line = []
                line_len = 0
            line.append(word)
            line_len += len(word)
        result.append(' '.join(line).ljust(maxWidth))
        return result
