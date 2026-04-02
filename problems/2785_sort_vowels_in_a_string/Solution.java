import java.util.*;

class Solution {
    public String sortVowels(String s) {
        String v = "aeiouAEIOU";
        List<Character> vowels = new ArrayList<>();
        for (char c : s.toCharArray()) if (v.indexOf(c) >= 0) vowels.add(c);
        Collections.sort(vowels);
        char[] res = s.toCharArray();
        int j = 0;
        for (int i = 0; i < res.length; i++) if (v.indexOf(res[i]) >= 0) res[i] = vowels.get(j++);
        return new String(res);
    }
}
