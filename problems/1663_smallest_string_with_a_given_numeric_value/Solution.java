import java.util.*;

class Solution {
    public String getSmallestString(int n, int k) {
        char[] result = new char[n];
        Arrays.fill(result, 'a');
        k -= n;
        for (int i = n - 1; i >= 0 && k > 0; i--) {
            int add = Math.min(25, k);
            result[i] = (char)('a' + add);
            k -= add;
        }
        return new String(result);
    }
}
