import java.util.*;

class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        int total = 0;
        for (int i = 0; i < word.length(); i += k) {
            String s = word.substring(i, i + k);
            cnt.merge(s, 1, Integer::sum);
            total++;
        }
        return total - Collections.max(cnt.values());
    }
}
