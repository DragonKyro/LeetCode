import java.util.*;

class Solution {
    public int fillCups(int[] amount) {
        int result = 0;
        while (true) {
            Arrays.sort(amount);
            if (amount[2] == 0) break;
            if (amount[1] == 0) { result += amount[2]; break; }
            amount[2]--; amount[1]--; result++;
        }
        return result;
    }
}
