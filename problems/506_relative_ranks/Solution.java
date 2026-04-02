import java.util.*;

class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) idx[i] = i;
        Arrays.sort(idx, (a, b) -> score[b] - score[a]);
        String[] res = new String[n];
        String[] medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < n; i++) {
            res[idx[i]] = i < 3 ? medals[i] : String.valueOf(i + 1);
        }
        return res;
    }
}
