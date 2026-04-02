import java.util.*;

class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> res = new ArrayList<>();
        for (int len = String.valueOf(low).length(); len <= String.valueOf(high).length(); len++) {
            for (int start = 1; start <= 9 - len + 1; start++) {
                int num = 0;
                for (int i = 0; i < len; i++) num = num * 10 + start + i;
                if (num >= low && num <= high) res.add(num);
            }
        }
        return res;
    }
}
