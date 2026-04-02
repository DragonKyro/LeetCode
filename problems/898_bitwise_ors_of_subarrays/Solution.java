import java.util.*;

class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> result = new HashSet<>(), current = new HashSet<>();
        for (int x : arr) {
            Set<Integer> next = new HashSet<>();
            next.add(x);
            for (int y : current) next.add(x | y);
            result.addAll(next);
            current = next;
        }
        return result.size();
    }
}
