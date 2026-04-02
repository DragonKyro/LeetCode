import java.util.*;

class Solution {
    public int uniqueLetterString(String s) {
        int[][] index = new int[26][2];
        for (int[] a : index) Arrays.fill(a, -1);
        int result = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - 'A';
            result += (i - index[c][1]) * (index[c][1] - index[c][0]);
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (int c = 0; c < 26; c++)
            result += (n - index[c][1]) * (index[c][1] - index[c][0]);
        return result;
    }
}
