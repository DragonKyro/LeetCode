import java.util.*;

class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int result = 0, j = 0;
        for (int house : houses) {
            while (j < heaters.length - 1 && Math.abs(heaters[j + 1] - house) <= Math.abs(heaters[j] - house)) j++;
            result = Math.max(result, Math.abs(heaters[j] - house));
        }
        return result;
    }
}
