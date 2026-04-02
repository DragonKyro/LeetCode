import java.util.*;

class Solution {
    List<String> res = new ArrayList<>();
    public List<String> removeInvalidParentheses(String s) {
        int left = 0, right = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        dfs(s, 0, left, right);
        return res;
    }
    private void dfs(String s, int start, int left, int right) {
        if (left == 0 && right == 0) {
            if (isValid(s)) res.add(s);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (i > start && s.charAt(i) == s.charAt(i - 1)) continue;
            if (s.charAt(i) == ')' && right > 0)
                dfs(s.substring(0, i) + s.substring(i + 1), i, left, right - 1);
            else if (s.charAt(i) == '(' && left > 0)
                dfs(s.substring(0, i) + s.substring(i + 1), i, left - 1, right);
        }
    }
    private boolean isValid(String s) {
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
}
