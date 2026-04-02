import java.util.*;

class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> count = new HashMap<>();
        int left = 0, result = 0;
        for (int right = 0; right < fruits.length; right++) {
            count.merge(fruits[right], 1, Integer::sum);
            while (count.size() > 2) {
                count.merge(fruits[left], -1, Integer::sum);
                if (count.get(fruits[left]) == 0) count.remove(fruits[left]);
                left++;
            }
            result = Math.max(result, right - left + 1);
        }
        return result;
    }
}
