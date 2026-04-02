class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack = [collections.Counter()]
        i = 0
        n = len(formula)
        while i < n:
            if formula[i] == '(':
                stack.append(collections.Counter())
                i += 1
            elif formula[i] == ')':
                i += 1
                start = i
                while i < n and formula[i].isdigit():
                    i += 1
                mult = int(formula[start:i] or 1)
                top = stack.pop()
                for name, cnt in top.items():
                    stack[-1][name] += cnt * mult
            else:
                start = i
                i += 1
                while i < n and formula[i].islower():
                    i += 1
                name = formula[start:i]
                start = i
                while i < n and formula[i].isdigit():
                    i += 1
                cnt = int(formula[start:i] or 1)
                stack[-1][name] += cnt
        result = []
        for name in sorted(stack[-1]):
            result.append(name)
            if stack[-1][name] > 1:
                result.append(str(stack[-1][name]))
        return ''.join(result)
