class Solution {
    public int longestBeautifulSubstring(String word) {
        int maxLen = 0, count = 1, distinct = 1;
        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i) >= word.charAt(i - 1)) {
                count++;
                if (word.charAt(i) != word.charAt(i - 1)) distinct++;
            } else {
                count = 1;
                distinct = 1;
            }
            if (distinct == 5) maxLen = Math.max(maxLen, count);
        }
        return maxLen;
    }
}
