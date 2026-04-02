import java.util.*;

class Solution {
    public int evaluate(String expression) {
        return parse(expression, new ArrayList<>());
    }

    private int parse(String expr, List<Map<String, Integer>> scope) {
        if (expr.charAt(0) != '(') {
            if (Character.isDigit(expr.charAt(0)) || expr.charAt(0) == '-') return Integer.parseInt(expr);
            for (int i = scope.size() - 1; i >= 0; i--)
                if (scope.get(i).containsKey(expr)) return scope.get(i).get(expr);
            return 0;
        }
        String inner = expr.substring(1, expr.length() - 1);
        List<String> tokens = tokenize(inner);
        if (tokens.get(0).equals("let")) {
            scope.add(new HashMap<>());
            int i = 1;
            while (i < tokens.size() - 1) {
                String var = tokens.get(i);
                int val = parse(tokens.get(i + 1), scope);
                scope.get(scope.size() - 1).put(var, val);
                i += 2;
            }
            int result = parse(tokens.get(tokens.size() - 1), scope);
            scope.remove(scope.size() - 1);
            return result;
        } else if (tokens.get(0).equals("add")) {
            return parse(tokens.get(1), scope) + parse(tokens.get(2), scope);
        } else {
            return parse(tokens.get(1), scope) * parse(tokens.get(2), scope);
        }
    }

    private List<String> tokenize(String s) {
        List<String> tokens = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            if (s.charAt(i) == ' ') { i++; continue; }
            if (s.charAt(i) == '(') {
                int depth = 1, j = i + 1;
                while (depth > 0) { if (s.charAt(j) == '(') depth++; else if (s.charAt(j) == ')') depth--; j++; }
                tokens.add(s.substring(i, j)); i = j;
            } else {
                int j = i;
                while (j < s.length() && s.charAt(j) != ' ') j++;
                tokens.add(s.substring(i, j)); i = j;
            }
        }
        return tokens;
    }
}
