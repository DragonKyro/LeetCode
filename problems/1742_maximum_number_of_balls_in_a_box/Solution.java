import java.util.*;

class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        Map<Integer, Integer> boxes = new HashMap<>();
        int max = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0, n = i;
            while (n > 0) { sum += n % 10; n /= 10; }
            boxes.merge(sum, 1, Integer::sum);
            max = Math.max(max, boxes.get(sum));
        }
        return max;
    }
}
