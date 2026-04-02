import java.util.*;

class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int count = 0;
        for (int c : costs) {
            if (coins >= c) { coins -= c; count++; }
            else break;
        }
        return count;
    }
}
