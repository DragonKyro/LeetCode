import java.util.*;

class Solution {
    public String countOfAtoms(String formula) {
        Deque<Map<String, Integer>> stack = new ArrayDeque<>();
        stack.push(new TreeMap<>());
        int i = 0, n = formula.length();
        while (i < n) {
            if (formula.charAt(i) == '(') {
                stack.push(new TreeMap<>());
                i++;
            } else if (formula.charAt(i) == ')') {
                i++;
                int start = i;
                while (i < n && Character.isDigit(formula.charAt(i))) i++;
                int mult = start < i ? Integer.parseInt(formula.substring(start, i)) : 1;
                Map<String, Integer> top = stack.pop();
                for (var entry : top.entrySet())
                    stack.peek().merge(entry.getKey(), entry.getValue() * mult, Integer::sum);
            } else {
                int start = i++;
                while (i < n && Character.isLowerCase(formula.charAt(i))) i++;
                String name = formula.substring(start, i);
                start = i;
                while (i < n && Character.isDigit(formula.charAt(i))) i++;
                int cnt = start < i ? Integer.parseInt(formula.substring(start, i)) : 1;
                stack.peek().merge(name, cnt, Integer::sum);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (var entry : new TreeMap<>(stack.peek()).entrySet()) {
            sb.append(entry.getKey());
            if (entry.getValue() > 1) sb.append(entry.getValue());
        }
        return sb.toString();
    }
}
