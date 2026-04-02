class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        max_len = 0
        count = 1
        distinct = 1
        for i in range(1, len(word)):
            if word[i] >= word[i - 1]:
                count += 1
                if word[i] != word[i - 1]:
                    distinct += 1
            else:
                count = 1
                distinct = 1
            if distinct == 5:
                max_len = max(max_len, count)
        return max_len
