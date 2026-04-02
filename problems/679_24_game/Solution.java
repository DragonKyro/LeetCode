import java.util.*;

class Solution {
    public boolean judgePoint24(int[] cards) {
        List<Double> list = new ArrayList<>();
        for (int c : cards) list.add((double) c);
        return solve(list);
    }
    private boolean solve(List<Double> nums) {
        if (nums.size() == 1) return Math.abs(nums.get(0) - 24) < 1e-6;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                List<Double> rest = new ArrayList<>();
                for (int k = 0; k < nums.size(); k++) if (k != i && k != j) rest.add(nums.get(k));
                double a = nums.get(i), b = nums.get(j);
                double[] ops = {a + b, a - b, a * b};
                for (double val : ops) { rest.add(val); if (solve(rest)) return true; rest.remove(rest.size() - 1); }
                if (Math.abs(b) > 1e-6) { rest.add(a / b); if (solve(rest)) return true; rest.remove(rest.size() - 1); }
            }
        }
        return false;
    }
}
