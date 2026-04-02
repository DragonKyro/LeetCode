import java.util.*;

class Solution {
    public int splitNum(int num) {
        char[] d = String.valueOf(num).toCharArray();
        Arrays.sort(d);
        int a = 0, b = 0;
        for (int i = 0; i < d.length; i++) {
            if (i % 2 == 0) a = a * 10 + (d[i] - '0');
            else b = b * 10 + (d[i] - '0');
        }
        return a + b;
    }
}
