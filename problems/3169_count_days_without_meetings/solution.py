from typing import List


class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        busy = 0
        end = 0
        for s, e in meetings:
            s = max(s, end + 1)
            if s <= e:
                busy += e - s + 1
                end = max(end, e)
        return days - busy
