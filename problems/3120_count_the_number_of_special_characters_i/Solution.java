import java.util.*;

class Solution {
    public int numberOfSpecialChars(String word) {
        Set<Character> s = new HashSet<>();
        for (char c : word.toCharArray()) s.add(c);
        int res = 0;
        for (char c = 'a'; c <= 'z'; c++)
            if (s.contains(c) && s.contains((char)(c - 32))) res++;
        return res;
    }
}
