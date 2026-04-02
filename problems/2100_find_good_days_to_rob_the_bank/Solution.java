import java.util.*;

class Solution {
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        int n = security.length;
        int[] dec = new int[n], inc = new int[n];
        for (int i = 1; i < n; i++)
            if (security[i] <= security[i - 1]) dec[i] = dec[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (security[i] <= security[i + 1]) inc[i] = inc[i + 1] + 1;
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++)
            if (dec[i] >= time && inc[i] >= time) result.add(i);
        return result;
    }
}
