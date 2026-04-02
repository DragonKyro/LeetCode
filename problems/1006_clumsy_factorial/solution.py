class Solution:
    def clumsy(self, n: int) -> int:
        stack = [n]
        n -= 1
        idx = 0
        ops = ['*', '//', '+', '-']
        while n > 0:
            op = ops[idx % 4]
            if op == '*':
                stack[-1] *= n
            elif op == '//':
                stack[-1] = int(stack[-1] / n)
            elif op == '+':
                stack.append(n)
            else:
                stack.append(-n)
            idx += 1
            n -= 1
        return sum(stack)
