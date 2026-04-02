class Solution {
    public String solveEquation(String equation) {
        String[] parts = equation.split("=");
        int[] left = parse(parts[0]);
        int[] right = parse(parts[1]);
        int coef = left[0] - right[0];
        int val = right[1] - left[1];
        if (coef == 0) return val == 0 ? "Infinite solutions" : "No solution";
        return "x=" + (val / coef);
    }
    private int[] parse(String expr) {
        int coef = 0, val = 0;
        String[] tokens = expr.replace("-", "+-").split("\\+");
        for (String token : tokens) {
            if (token.isEmpty()) continue;
            if (token.contains("x")) {
                String t = token.replace("x", "");
                if (t.isEmpty() || t.equals("+")) coef += 1;
                else if (t.equals("-")) coef -= 1;
                else coef += Integer.parseInt(t);
            } else {
                val += Integer.parseInt(token);
            }
        }
        return new int[]{coef, val};
    }
}
