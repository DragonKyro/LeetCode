import java.util.*;

class Solution {
    public List<Integer> splitIntoFibonacci(String num) {
        List<Integer> result = new ArrayList<>();
        backtrack(num, 0, result);
        return result;
    }
    boolean backtrack(String num, int idx, List<Integer> seq) {
        if (idx == num.length()) return seq.size() >= 3;
        for (int i = idx + 1; i <= num.length(); i++) {
            if (num.charAt(idx) == '0' && i > idx + 1) break;
            long val = Long.parseLong(num.substring(idx, i));
            if (val > Integer.MAX_VALUE) break;
            if (seq.size() >= 2) {
                long sum = (long) seq.get(seq.size()-1) + seq.get(seq.size()-2);
                if (val > sum) break;
                if (val < sum) continue;
            }
            seq.add((int) val);
            if (backtrack(num, i, seq)) return true;
            seq.remove(seq.size() - 1);
        }
        return false;
    }
}
