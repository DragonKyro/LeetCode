from typing import List


class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count = Counter(students)
        for i, s in enumerate(sandwiches):
            if count[s] > 0:
                count[s] -= 1
            else:
                return len(sandwiches) - i
        return 0
