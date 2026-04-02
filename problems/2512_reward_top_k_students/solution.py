from typing import List


class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        pos, neg = set(positive_feedback), set(negative_feedback)
        scores = []
        for i, r in enumerate(report):
            score = 0
            for w in r.split():
                if w in pos: score += 3
                elif w in neg: score -= 1
            scores.append((-score, student_id[i]))
        scores.sort()
        return [s[1] for s in scores[:k]]
