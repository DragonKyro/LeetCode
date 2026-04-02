import java.util.*;

class Solution {
    public String longestWord(String[] words) {
        Set<String> set = new HashSet<>(Arrays.asList(words));
        String ans = "";
        for (String word : words) {
            if (word.length() > ans.length() || (word.length() == ans.length() && word.compareTo(ans) < 0)) {
                boolean valid = true;
                for (int k = 1; k < word.length(); k++) {
                    if (!set.contains(word.substring(0, k))) { valid = false; break; }
                }
                if (valid) ans = word;
            }
        }
        return ans;
    }
}
