class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        counts = [0] * 10
        cows = 0
        for s, g in zip(secret, guess):
            if s == g:
                bulls += 1
            else:
                if counts[int(s)] < 0:
                    cows += 1
                counts[int(s)] += 1
                if counts[int(g)] > 0:
                    cows += 1
                counts[int(g)] -= 1
        return f"{bulls}A{cows}B"
