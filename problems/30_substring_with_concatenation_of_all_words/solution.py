from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        word_len = len(words[0])
        num_words = len(words)
        total_len = word_len * num_words
        word_count = {}
        for w in words:
            word_count[w] = word_count.get(w, 0) + 1
        res = []
        for i in range(word_len):
            left = i
            count = {}
            matched = 0
            for j in range(i, len(s) - word_len + 1, word_len):
                word = s[j:j + word_len]
                if word in word_count:
                    count[word] = count.get(word, 0) + 1
                    matched += 1
                    while count[word] > word_count[word]:
                        left_word = s[left:left + word_len]
                        count[left_word] -= 1
                        matched -= 1
                        left += word_len
                    if matched == num_words:
                        res.append(left)
                else:
                    count.clear()
                    matched = 0
                    left = j + word_len
        return res
