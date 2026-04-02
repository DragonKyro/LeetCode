class Solution {
    public boolean areOccurrencesEqual(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) count[c - 'a']++;
        int target = count[s.charAt(0) - 'a'];
        for (int c : count) if (c > 0 && c != target) return false;
        return true;
    }
}
