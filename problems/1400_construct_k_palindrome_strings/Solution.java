class Solution {
    public boolean canConstruct(String s, int k) {
        if (k > s.length()) return false;
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) cnt[c-'a']++;
        int odd = 0;
        for (int c : cnt) if (c % 2 == 1) odd++;
        return odd <= k;
    }
}
