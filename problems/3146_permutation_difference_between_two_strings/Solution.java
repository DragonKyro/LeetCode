class Solution {
    public int findPermutationDifference(String s, String t) {
        int[] ps = new int[26], pt = new int[26];
        for (int i = 0; i < s.length(); i++) { ps[s.charAt(i)-'a'] = i; pt[t.charAt(i)-'a'] = i; }
        int res = 0;
        for (int i = 0; i < 26; i++) res += Math.abs(ps[i] - pt[i]);
        return res;
    }
}
