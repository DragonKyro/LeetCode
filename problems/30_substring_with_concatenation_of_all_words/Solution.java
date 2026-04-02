import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (s.isEmpty() || words.length == 0) return res;
        int wordLen = words[0].length(), numWords = words.length;
        Map<String, Integer> wordCount = new HashMap<>();
        for (String w : words) wordCount.merge(w, 1, Integer::sum);
        for (int i = 0; i < wordLen; i++) {
            int left = i, matched = 0;
            Map<String, Integer> count = new HashMap<>();
            for (int j = i; j <= s.length() - wordLen; j += wordLen) {
                String word = s.substring(j, j + wordLen);
                if (wordCount.containsKey(word)) {
                    count.merge(word, 1, Integer::sum);
                    matched++;
                    while (count.get(word) > wordCount.get(word)) {
                        String lw = s.substring(left, left + wordLen);
                        count.merge(lw, -1, Integer::sum);
                        matched--;
                        left += wordLen;
                    }
                    if (matched == numWords) res.add(left);
                } else {
                    count.clear();
                    matched = 0;
                    left = j + wordLen;
                }
            }
        }
        return res;
    }
}
