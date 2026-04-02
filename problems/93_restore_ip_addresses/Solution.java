import java.util.*;

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        backtrack(s, 0, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(String s, int start, List<String> parts, List<String> result) {
        if (parts.size() == 4) {
            if (start == s.length()) result.add(String.join(".", parts));
            return;
        }
        for (int len = 1; len <= 3 && start + len <= s.length(); len++) {
            String segment = s.substring(start, start + len);
            if ((segment.startsWith("0") && len > 1) || Integer.parseInt(segment) > 255) continue;
            parts.add(segment);
            backtrack(s, start + len, parts, result);
            parts.remove(parts.size() - 1);
        }
    }
}
