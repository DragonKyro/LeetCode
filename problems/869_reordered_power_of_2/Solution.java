import java.util.*;

class Solution {
    public boolean reorderedPowerOf2(int n) {
        char[] target = String.valueOf(n).toCharArray();
        Arrays.sort(target);
        for (int i = 0; i < 31; i++) {
            char[] cand = String.valueOf(1 << i).toCharArray();
            Arrays.sort(cand);
            if (Arrays.equals(target, cand)) return true;
        }
        return false;
    }
}
