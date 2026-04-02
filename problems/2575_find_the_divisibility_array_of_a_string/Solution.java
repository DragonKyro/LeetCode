class Solution {
    public int[] divisibilityArray(String word, int m) {
        int[] ans = new int[word.length()];
        long rem = 0;
        for (int i = 0; i < word.length(); i++) {
            rem = (rem * 10 + (word.charAt(i)-'0')) % m;
            ans[i] = rem == 0 ? 1 : 0;
        }
        return ans;
    }
}
