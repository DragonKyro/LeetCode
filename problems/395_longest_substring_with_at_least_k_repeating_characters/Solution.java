class Solution {
    public int longestSubstring(String s, int k) {
        if (s.length() < k) return 0;
        int[] count = new int[26];
        for (char c : s.toCharArray()) count[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            char c = (char)('a' + i);
            if (count[i] > 0 && count[i] < k) {
                int res = 0;
                for (String sub : s.split(String.valueOf(c)))
                    res = Math.max(res, longestSubstring(sub, k));
                return res;
            }
        }
        return s.length();
    }
}
