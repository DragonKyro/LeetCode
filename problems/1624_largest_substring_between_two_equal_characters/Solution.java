import java.util.*;

class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[] first = new int[26];
        Arrays.fill(first, -1);
        int result = -1;
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            if (first[c] != -1) {
                result = Math.max(result, i - first[c] - 1);
            } else {
                first[c] = i;
            }
        }
        return result;
    }
}
