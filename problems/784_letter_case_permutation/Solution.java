import java.util.*;

class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> result = new ArrayList<>();
        result.add("");
        for (char c : s.toCharArray()) {
            List<String> next = new ArrayList<>();
            for (String r : result) {
                if (Character.isLetter(c)) {
                    next.add(r + Character.toLowerCase(c));
                    next.add(r + Character.toUpperCase(c));
                } else {
                    next.add(r + c);
                }
            }
            result = next;
        }
        return result;
    }
}
