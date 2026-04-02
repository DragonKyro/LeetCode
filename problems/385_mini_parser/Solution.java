import java.util.*;

class Solution {
    public NestedInteger deserialize(String s) {
        if (s.charAt(0) != '[') return new NestedInteger(Integer.parseInt(s));
        Deque<NestedInteger> stack = new ArrayDeque<>();
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '[') {
                stack.push(new NestedInteger());
                start = i + 1;
            } else if (c == ',' || c == ']') {
                if (i > start && start < s.length()) {
                    String num = s.substring(start, i);
                    if (!num.isEmpty()) stack.peek().add(new NestedInteger(Integer.parseInt(num)));
                }
                start = i + 1;
                if (c == ']' && stack.size() > 1) {
                    NestedInteger top = stack.pop();
                    stack.peek().add(top);
                }
            }
        }
        return stack.peek();
    }
}
