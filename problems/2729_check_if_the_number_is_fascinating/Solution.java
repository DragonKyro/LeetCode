import java.util.*;

class Solution {
    public boolean isFascinating(int n) {
        String s = "" + n + (2*n) + (3*n);
        if (s.length() != 9) return false;
        char[] arr = s.toCharArray(); Arrays.sort(arr);
        return new String(arr).equals("123456789");
    }
}
