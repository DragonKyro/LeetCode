import java.util.*;

class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] wordFreqs = new int[words.length];
        for (int i = 0; i < words.length; i++) wordFreqs[i] = f(words[i]);
        Arrays.sort(wordFreqs);
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int qf = f(queries[i]);
            int lo = 0, hi = wordFreqs.length;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (wordFreqs[mid] <= qf) lo = mid + 1;
                else hi = mid;
            }
            result[i] = wordFreqs.length - lo;
        }
        return result;
    }
    private int f(String s) {
        char min = 'z' + 1;
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c < min) { min = c; count = 1; }
            else if (c == min) count++;
        }
        return count;
    }
}
