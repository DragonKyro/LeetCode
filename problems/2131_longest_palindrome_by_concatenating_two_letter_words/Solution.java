import java.util.*;

class Solution {
    public int longestPalindrome(String[] words) {
        Map<String, Integer> freq = new HashMap<>();
        for (String w : words) freq.merge(w, 1, Integer::sum);
        int length = 0;
        boolean hasCenter = false;
        for (var entry : freq.entrySet()) {
            String word = entry.getKey();
            int count = entry.getValue();
            String rev = new StringBuilder(word).reverse().toString();
            if (word.equals(rev)) {
                length += (count / 2) * 4;
                if (count % 2 == 1) hasCenter = true;
            } else if (word.compareTo(rev) < 0 && freq.containsKey(rev)) {
                length += Math.min(count, freq.get(rev)) * 4;
            }
        }
        if (hasCenter) length += 2;
        return length;
    }
}
