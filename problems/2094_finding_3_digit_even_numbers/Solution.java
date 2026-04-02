import java.util.*;

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] freq = new int[10];
        for (int d : digits) freq[d]++;
        List<Integer> result = new ArrayList<>();
        for (int num = 100; num < 1000; num += 2) {
            int[] needed = new int[10];
            int temp = num;
            while (temp > 0) { needed[temp % 10]++; temp /= 10; }
            boolean valid = true;
            for (int i = 0; i < 10; i++) {
                if (needed[i] > freq[i]) { valid = false; break; }
            }
            if (valid) result.add(num);
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
