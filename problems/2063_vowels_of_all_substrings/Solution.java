class Solution {
    public long countVowels(String word) {
        long result = 0;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            if ("aeiou".indexOf(word.charAt(i)) >= 0) {
                result += (long)(i + 1) * (n - i);
            }
        }
        return result;
    }
}
