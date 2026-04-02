class Solution {
    public int similarPairs(String[] words) {
        int count = 0;
        for (int i = 0; i < words.length; i++) {
            int a = mask(words[i]);
            for (int j = i + 1; j < words.length; j++)
                if (a == mask(words[j])) count++;
        }
        return count;
    }
    int mask(String s) { int m = 0; for (char c : s.toCharArray()) m |= 1 << (c - 'a'); return m; }
}
