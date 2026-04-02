class Solution:
    def palindromePairs(self, words: list[str]) -> list[list[int]]:
        word_map = {w: i for i, w in enumerate(words)}
        res = []
        for i, word in enumerate(words):
            for j in range(len(word) + 1):
                prefix = word[:j]
                suffix = word[j:]
                if prefix == prefix[::-1]:
                    rev_suffix = suffix[::-1]
                    if rev_suffix in word_map and word_map[rev_suffix] != i:
                        res.append([word_map[rev_suffix], i])
                if j != len(word) and suffix == suffix[::-1]:
                    rev_prefix = prefix[::-1]
                    if rev_prefix in word_map and word_map[rev_prefix] != i:
                        res.append([i, word_map[rev_prefix]])
        return res
