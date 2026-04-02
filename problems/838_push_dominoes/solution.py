class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        d = list(dominoes)
        n = len(d)
        forces = [0] * n
        f = 0
        for i in range(n):
            if d[i] == 'R': f = n
            elif d[i] == 'L': f = 0
            else: f = max(f - 1, 0)
            forces[i] += f
        f = 0
        for i in range(n - 1, -1, -1):
            if d[i] == 'L': f = n
            elif d[i] == 'R': f = 0
            else: f = max(f - 1, 0)
            forces[i] -= f
        return ''.join('.' if x == 0 else ('R' if x > 0 else 'L') for x in forces)
