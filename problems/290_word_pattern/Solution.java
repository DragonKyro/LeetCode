import java.util.*;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) return false;
        Map<Character, String> pToW = new HashMap<>();
        Map<String, Character> wToP = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            char p = pattern.charAt(i);
            String w = words[i];
            if (pToW.containsKey(p) && !pToW.get(p).equals(w)) return false;
            if (wToP.containsKey(w) && wToP.get(w) != p) return false;
            pToW.put(p, w);
            wToP.put(w, p);
        }
        return true;
    }
}
