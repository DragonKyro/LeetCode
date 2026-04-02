import java.util.*;

class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new ArrayList<>();
        for (String word : words) if (match(word, pattern)) result.add(word);
        return result;
    }
    boolean match(String w, String p) {
        Map<Character, Character> m1 = new HashMap<>(), m2 = new HashMap<>();
        for (int i = 0; i < w.length(); i++) {
            char a = w.charAt(i), b = p.charAt(i);
            if (m1.getOrDefault(a, b) != b || m2.getOrDefault(b, a) != a) return false;
            m1.put(a, b); m2.put(b, a);
        }
        return true;
    }
}
