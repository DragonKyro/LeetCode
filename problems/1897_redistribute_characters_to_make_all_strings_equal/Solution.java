class Solution {
    public boolean makeEqual(String[] words) {
        int[] count = new int[26];
        for (String w : words) for (char c : w.toCharArray()) count[c - 'a']++;
        int n = words.length;
        for (int c : count) if (c % n != 0) return false;
        return true;
    }
}
