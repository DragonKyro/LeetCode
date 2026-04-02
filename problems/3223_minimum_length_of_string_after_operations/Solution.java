class Solution {
    public int minimumLength(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) cnt[c-'a']++;
        int res = 0;
        for (int v : cnt) if (v > 0) res += v % 2 == 0 ? 2 : 1;
        return res;
    }
}
