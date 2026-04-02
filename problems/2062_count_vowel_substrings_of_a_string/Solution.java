import java.util.*;

class Solution {
    public int countVowelSubstrings(String word) {
        String vowels = "aeiou";
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            Set<Character> seen = new HashSet<>();
            for (int j = i; j < word.length(); j++) {
                if (vowels.indexOf(word.charAt(j)) == -1) break;
                seen.add(word.charAt(j));
                if (seen.size() == 5) count++;
            }
        }
        return count;
    }
}
