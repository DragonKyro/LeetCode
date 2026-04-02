import java.util.*;

class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int res = 0, prefix = 0;
        for (int i = satisfaction.length - 1; i >= 0; i--) {
            prefix += satisfaction[i];
            if (prefix <= 0) break;
            res += prefix;
        }
        return res;
    }
}
