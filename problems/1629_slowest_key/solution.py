from typing import List


class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        longest = releaseTimes[0]
        result = keysPressed[0]
        for i in range(1, len(releaseTimes)):
            duration = releaseTimes[i] - releaseTimes[i - 1]
            if duration > longest or (duration == longest and keysPressed[i] > result):
                longest = duration
                result = keysPressed[i]
        return result
