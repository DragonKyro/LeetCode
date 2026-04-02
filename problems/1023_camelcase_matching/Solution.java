import java.util.*;

class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> res = new ArrayList<>();
        for (String q : queries) res.add(matches(q, pattern));
        return res;
    }
    private boolean matches(String query, String pattern) {
        int j = 0;
        for (char c : query.toCharArray()) {
            if (j < pattern.length() && c == pattern.charAt(j)) j++;
            else if (Character.isUpperCase(c)) return false;
        }
        return j == pattern.length();
    }
}
