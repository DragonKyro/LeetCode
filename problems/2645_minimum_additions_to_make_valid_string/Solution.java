class Solution {
    public int addMinimum(String word) {
        int ans = 0, j = 0, i = 0;
        String t = "abc";
        while (i < word.length()) {
            if (word.charAt(i) == t.charAt(j)) i++;
            else ans++;
            j = (j+1) % 3;
        }
        return ans + (3-j)%3;
    }
}
