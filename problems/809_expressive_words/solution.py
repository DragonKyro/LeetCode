from typing import List


class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        def get_groups(w: str):
            groups = []
            i = 0
            while i < len(w):
                j = i
                while j < len(w) and w[j] == w[i]:
                    j += 1
                groups.append((w[i], j - i))
                i = j
            return groups
        sg = get_groups(s)
        count = 0
        for word in words:
            wg = get_groups(word)
            if len(sg) != len(wg):
                continue
            valid = True
            for (sc, sn), (wc, wn) in zip(sg, wg):
                if sc != wc or (sn < wn) or (sn != wn and sn < 3):
                    valid = False
                    break
            if valid:
                count += 1
        return count
