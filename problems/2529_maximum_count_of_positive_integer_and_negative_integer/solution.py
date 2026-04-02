class Solution:
    def countVowelStrings(self, n: int) -> int:
        vowels = 'aeiou'
        count = 0
        def dfs(idx, length):
            nonlocal count
            if length == n:
                count += 1
                return
            for i in range(idx, 5):
                dfs(i, length + 1)
        dfs(0, 0)
        return count
