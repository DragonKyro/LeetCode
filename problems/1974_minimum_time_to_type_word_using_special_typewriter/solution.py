class Solution:
    def minTimeToType(self, word: str) -> int:
        time = 0
        curr = 0
        for c in word:
            target = ord(c) - ord('a')
            diff = abs(target - curr)
            time += min(diff, 26 - diff) + 1
            curr = target
        return time
