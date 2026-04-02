class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] charCount = new int[26];
        for (char c : chars.toCharArray()) charCount[c - 'a']++;
        int result = 0;
        for (String word : words) {
            int[] wc = new int[26];
            for (char c : word.toCharArray()) wc[c - 'a']++;
            boolean valid = true;
            for (int i = 0; i < 26; i++) {
                if (wc[i] > charCount[i]) { valid = false; break; }
            }
            if (valid) result += word.length();
        }
        return result;
    }
}
