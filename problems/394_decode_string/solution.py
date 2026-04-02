class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        cur_str = ''
        cur_num = 0
        for c in s:
            if c == '[':
                stack.append((cur_str, cur_num))
                cur_str = ''
                cur_num = 0
            elif c == ']':
                prev_str, num = stack.pop()
                cur_str = prev_str + num * cur_str
            elif c.isdigit():
                cur_num = cur_num * 10 + int(c)
            else:
                cur_str += c
        return cur_str
