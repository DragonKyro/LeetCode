class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] target = new int[26];
        for (char c : licensePlate.toLowerCase().toCharArray())
            if (Character.isLetter(c)) target[c - 'a']++;
        String result = null;
        for (String word : words) {
            int[] wc = new int[26];
            for (char c : word.toLowerCase().toCharArray()) wc[c - 'a']++;
            boolean valid = true;
            for (int i = 0; i < 26; i++)
                if (wc[i] < target[i]) { valid = false; break; }
            if (valid && (result == null || word.length() < result.length()))
                result = word;
        }
        return result;
    }
}
