import java.util.*;

class Solution {
    public int numSplits(String s) {
        Map<Character, Integer> left = new HashMap<>(), right = new HashMap<>();
        for (char c : s.toCharArray()) right.merge(c, 1, Integer::sum);
        int res = 0;
        for (char c : s.toCharArray()) {
            left.merge(c, 1, Integer::sum);
            right.merge(c, -1, Integer::sum);
            if (right.get(c) == 0) right.remove(c);
            if (left.size() == right.size()) res++;
        }
        return res;
    }
}
