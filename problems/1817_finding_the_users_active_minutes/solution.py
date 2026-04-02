from typing import List


class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        from collections import defaultdict
        user_minutes = defaultdict(set)
        for uid, minute in logs:
            user_minutes[uid].add(minute)
        answer = [0] * k
        for uid in user_minutes:
            uam = len(user_minutes[uid])
            if uam <= k:
                answer[uam - 1] += 1
        return answer
