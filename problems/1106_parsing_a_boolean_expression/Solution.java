import java.util.*;

class Solution {
    public boolean parseBoolExpr(String expression) {
        Deque<Character> stack = new ArrayDeque<>();
        for (char ch : expression.toCharArray()) {
            if (ch == ',') continue;
            if (ch == ')') {
                List<Character> seen = new ArrayList<>();
                while (stack.peek() != '(') {
                    seen.add(stack.pop());
                }
                stack.pop();
                char op = stack.pop();
                char result;
                if (op == '!') {
                    result = seen.get(0) == 't' ? 'f' : 't';
                } else if (op == '&') {
                    result = seen.contains('f') ? 'f' : 't';
                } else {
                    result = seen.contains('t') ? 't' : 'f';
                }
                stack.push(result);
            } else {
                stack.push(ch);
            }
        }
        return stack.peek() == 't';
    }
}
