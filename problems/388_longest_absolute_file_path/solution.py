class Solution:
    def lengthLongestPath(self, input: str) -> int:
        stack = []
        max_len = 0
        for line in input.split('\n'):
            level = line.count('\t')
            name = line.lstrip('\t')
            while len(stack) > level:
                stack.pop()
            length = (stack[-1] if stack else 0) + len(name) + 1
            stack.append(length)
            if '.' in name:
                max_len = max(max_len, length - 1)
        return max_len
