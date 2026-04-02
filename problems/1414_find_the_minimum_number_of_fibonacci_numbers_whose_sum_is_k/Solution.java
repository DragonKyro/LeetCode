import java.util.*;

class Solution {
    public int findMinFibonacciNumbers(int k) {
        List<Integer> fibs = new ArrayList<>(Arrays.asList(1, 1));
        while (fibs.get(fibs.size() - 1) < k) {
            int sz = fibs.size();
            fibs.add(fibs.get(sz - 1) + fibs.get(sz - 2));
        }
        int count = 0;
        for (int i = fibs.size() - 1; i >= 0 && k > 0; i--) {
            if (fibs.get(i) <= k) {
                k -= fibs.get(i);
                count++;
            }
        }
        return count;
    }
}
