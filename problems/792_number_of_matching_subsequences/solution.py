from typing import List


class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        waiting = collections.defaultdict(list)
        for word in words:
            waiting[word[0]].append(iter(word[1:]))
        for c in s:
            old = waiting[c]
            waiting[c] = []
            for it in old:
                nxt = next(it, None)
                if nxt is None:
                    waiting['#'].append(it)
                else:
                    waiting[nxt].append(it)
        return len(waiting['#'])
