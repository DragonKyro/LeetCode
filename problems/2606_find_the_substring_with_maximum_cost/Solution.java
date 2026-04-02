class Solution {
    public int maximumCostSubstring(String s, String chars, int[] vals) {
        int[] cost = new int[26];
        for (int i = 0; i < 26; i++) cost[i] = i+1;
        for (int i = 0; i < chars.length(); i++) cost[chars.charAt(i)-'a'] = vals[i];
        int ans = 0, cur = 0;
        for (char c : s.toCharArray()) { cur += cost[c-'a']; if (cur < 0) cur = 0; ans = Math.max(ans, cur); }
        return ans;
    }
}
