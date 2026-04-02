import java.util.*;

class Solution {
    int i = 0;
    public List<String> braceExpansionII(String expression) {
        Set<String> result = parse(expression);
        List<String> ans = new ArrayList<>(result);
        Collections.sort(ans);
        return ans;
    }
    private Set<String> parse(String s) {
        Set<String> result = new HashSet<>();
        Set<String> current = new HashSet<>();
        current.add("");
        while (i < s.length()) {
            if (s.charAt(i) == '{') {
                i++;
                Set<String> inner = parse(s);
                Set<String> next = new HashSet<>();
                for (String a : current) for (String b : inner) next.add(a + b);
                current = next;
            } else if (s.charAt(i) == '}') {
                i++;
                result.addAll(current);
                return result;
            } else if (s.charAt(i) == ',') {
                result.addAll(current);
                current = new HashSet<>();
                current.add("");
                i++;
            } else {
                int j = i;
                while (j < s.length() && Character.isLetter(s.charAt(j))) j++;
                String word = s.substring(i, j);
                Set<String> next = new HashSet<>();
                for (String a : current) next.add(a + word);
                current = next;
                i = j;
            }
        }
        result.addAll(current);
        return result;
    }
}
