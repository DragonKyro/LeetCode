class Solution {
    public int expressiveWords(String s, String[] words) {
        int count = 0;
        for (String word : words) {
            if (isStretchy(s, word)) count++;
        }
        return count;
    }
    boolean isStretchy(String s, String w) {
        int i = 0, j = 0;
        while (i < s.length() && j < w.length()) {
            if (s.charAt(i) != w.charAt(j)) return false;
            int si = i, wj = j;
            while (i < s.length() && s.charAt(i) == s.charAt(si)) i++;
            while (j < w.length() && w.charAt(j) == w.charAt(wj)) j++;
            int sLen = i - si, wLen = j - wj;
            if (sLen < wLen || (sLen != wLen && sLen < 3)) return false;
        }
        return i == s.length() && j == w.length();
    }
}
