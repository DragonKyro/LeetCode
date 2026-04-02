class Solution {
    public int takeCharacters(String s, int k) {
        int[] cnt = new int[3];
        for (char c : s.toCharArray()) cnt[c-'a']++;
        if (cnt[0]<k||cnt[1]<k||cnt[2]<k) return -1;
        int n = s.length(), ans = n, j = 0;
        int[] w = new int[3];
        for (int i = 0; i < n; i++) {
            w[s.charAt(i)-'a']++;
            while (cnt[0]-w[0]<k||cnt[1]-w[1]<k||cnt[2]-w[2]<k) w[s.charAt(j++)-'a']--;
            ans = Math.min(ans, n-(i-j+1));
        }
        return ans;
    }
}
