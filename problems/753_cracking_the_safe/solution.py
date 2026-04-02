class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        seen = set()
        result = []
        def dfs(node):
            for x in range(k):
                nei = node + str(x)
                if nei not in seen:
                    seen.add(nei)
                    dfs(nei[1:])
                    result.append(str(x))
        start = '0' * (n - 1)
        dfs(start)
        return ''.join(result) + start
