import java.util.*;

class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        dictionary.sort((a, b) -> a.length() != b.length() ? b.length() - a.length() : a.compareTo(b));
        for (String word : dictionary) {
            int i = 0;
            for (int j = 0; j < s.length() && i < word.length(); j++) {
                if (word.charAt(i) == s.charAt(j)) i++;
            }
            if (i == word.length()) return word;
        }
        return "";
    }
}
