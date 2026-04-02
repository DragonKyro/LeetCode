from typing import List


class Solution:
    def findSecretWord(self, words: List[str], master: 'Master') -> None:
        def matches(a: str, b: str) -> int:
            return sum(x == y for x, y in zip(a, b))
        for _ in range(10):
            guess = random.choice(words)
            m = master.guess(guess)
            if m == 6:
                return
            words = [w for w in words if matches(w, guess) == m]
