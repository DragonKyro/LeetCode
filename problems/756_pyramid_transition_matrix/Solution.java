import java.util.*;

class Solution {
    Map<String, List<Character>> mapping = new HashMap<>();

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        for (String s : allowed)
            mapping.computeIfAbsent(s.substring(0,2), k -> new ArrayList<>()).add(s.charAt(2));
        return solve(bottom, new StringBuilder(), 0);
    }

    private boolean solve(String bottom, StringBuilder next, int idx) {
        if (bottom.length() == 1) return true;
        if (idx == bottom.length() - 1) return solve(next.toString(), new StringBuilder(), 0);
        String key = bottom.substring(idx, idx + 2);
        for (char c : mapping.getOrDefault(key, new ArrayList<>())) {
            next.append(c);
            if (solve(bottom, next, idx + 1)) return true;
            next.deleteCharAt(next.length() - 1);
        }
        return false;
    }
}
