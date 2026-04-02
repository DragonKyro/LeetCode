import java.util.*;

class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> res = new ArrayList<>();
        backtrack(res, num, target, 0, "", 0, 0);
        return res;
    }

    private void backtrack(List<String> res, String num, int target, int idx, String path, long value, long prev) {
        if (idx == num.length()) {
            if (value == target) res.add(path);
            return;
        }
        for (int i = idx; i < num.length(); i++) {
            if (i > idx && num.charAt(idx) == '0') break;
            long curr = Long.parseLong(num.substring(idx, i + 1));
            if (idx == 0) {
                backtrack(res, num, target, i + 1, "" + curr, curr, curr);
            } else {
                backtrack(res, num, target, i + 1, path + "+" + curr, value + curr, curr);
                backtrack(res, num, target, i + 1, path + "-" + curr, value - curr, -curr);
                backtrack(res, num, target, i + 1, path + "*" + curr, value - prev + prev * curr, prev * curr);
            }
        }
    }
}
