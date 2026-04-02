import java.util.*;

class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> result = new ArrayList<>();
        for (int num = left; num <= right; num++) {
            boolean valid = true;
            int n = num;
            while (n > 0) {
                int d = n % 10;
                if (d == 0 || num % d != 0) { valid = false; break; }
                n /= 10;
            }
            if (valid) result.add(num);
        }
        return result;
    }
}
