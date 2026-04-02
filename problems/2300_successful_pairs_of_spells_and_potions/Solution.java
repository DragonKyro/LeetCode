import java.util.*;

class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int n = potions.length;
        int[] result = new int[spells.length];
        for (int i = 0; i < spells.length; i++) {
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) / 2;
                if ((long) spells[i] * potions[mid] >= success) right = mid;
                else left = mid + 1;
            }
            result[i] = n - left;
        }
        return result;
    }
}
