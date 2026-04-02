import java.util.*;

class Solution {
    Map<String, Integer> lookup;

    public List<String> basicCalculatorIV(String expression, String[] evalvars, int[] evalints) {
        lookup = new HashMap<>();
        for (int i = 0; i < evalvars.length; i++) lookup.put(evalvars[i], evalints[i]);
        List<String> tokens = tokenize(expression);
        Map<List<String>, Integer> poly = parseExpr(tokens, new int[]{0});
        List<Map.Entry<List<String>, Integer>> entries = new ArrayList<>(poly.entrySet());
        entries.removeIf(e -> e.getValue() == 0);
        entries.sort((a, b) -> {
            if (a.getKey().size() != b.getKey().size()) return b.getKey().size() - a.getKey().size();
            return a.getKey().toString().compareTo(b.getKey().toString());
        });
        List<String> result = new ArrayList<>();
        for (var e : entries) {
            StringBuilder sb = new StringBuilder();
            sb.append(e.getValue());
            for (String v : e.getKey()) sb.append('*').append(v);
            result.add(sb.toString());
        }
        return result;
    }

    List<String> tokenize(String s) {
        List<String> tokens = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            if (s.charAt(i) == ' ') { i++; continue; }
            if ("()*+-".indexOf(s.charAt(i)) >= 0) { tokens.add("" + s.charAt(i)); i++; }
            else {
                int j = i;
                while (j < s.length() && s.charAt(j) != ' ' && "()*+-".indexOf(s.charAt(j)) < 0) j++;
                tokens.add(s.substring(i, j)); i = j;
            }
        }
        return tokens;
    }

    Map<List<String>, Integer> parseExpr(List<String> tokens, int[] idx) {
        Map<List<String>, Integer> left = parseTerm(tokens, idx);
        while (idx[0] < tokens.size() && (tokens.get(idx[0]).equals("+") || tokens.get(idx[0]).equals("-"))) {
            String op = tokens.get(idx[0]++); Map<List<String>, Integer> right = parseTerm(tokens, idx);
            left = combine(left, right, op);
        }
        return left;
    }

    Map<List<String>, Integer> parseTerm(List<String> tokens, int[] idx) {
        Map<List<String>, Integer> left = parseFactor(tokens, idx);
        while (idx[0] < tokens.size() && tokens.get(idx[0]).equals("*")) {
            idx[0]++; Map<List<String>, Integer> right = parseFactor(tokens, idx);
            left = combine(left, right, "*");
        }
        return left;
    }

    Map<List<String>, Integer> parseFactor(List<String> tokens, int[] idx) {
        if (tokens.get(idx[0]).equals("(")) {
            idx[0]++; var result = parseExpr(tokens, idx); idx[0]++; return result;
        }
        String token = tokens.get(idx[0]++); Map<List<String>, Integer> m = new HashMap<>();
        if (lookup.containsKey(token)) m.put(new ArrayList<>(), lookup.get(token));
        else if (token.matches("-?\\d+")) m.put(new ArrayList<>(), Integer.parseInt(token));
        else { List<String> key = new ArrayList<>(); key.add(token); m.put(key, 1); }
        return m;
    }

    Map<List<String>, Integer> combine(Map<List<String>, Integer> a, Map<List<String>, Integer> b, String op) {
        Map<List<String>, Integer> result = new HashMap<>();
        if (op.equals("*")) {
            for (var e1 : a.entrySet()) for (var e2 : b.entrySet()) {
                List<String> key = new ArrayList<>(e1.getKey()); key.addAll(e2.getKey()); Collections.sort(key);
                result.merge(key, e1.getValue() * e2.getValue(), Integer::sum);
            }
        } else {
            for (var e : a.entrySet()) result.merge(e.getKey(), e.getValue(), Integer::sum);
            int sign = op.equals("+") ? 1 : -1;
            for (var e : b.entrySet()) result.merge(e.getKey(), sign * e.getValue(), Integer::sum);
        }
        return result;
    }
}
