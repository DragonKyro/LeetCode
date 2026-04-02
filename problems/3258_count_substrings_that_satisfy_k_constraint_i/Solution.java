class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int n = s.length(), res = 0, l = 0;
        int[] cnt = new int[2];
        for (int r = 0; r < n; r++) {
            cnt[s.charAt(r)-'0']++;
            while (cnt[0] > k && cnt[1] > k) cnt[s.charAt(l++)-'0']--;
            res += r - l + 1;
        }
        return res;
    }
}
