import java.util.*;

class Solution {
    public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
        Set<Integer> s = new TreeSet<>();
        for (int n : nums) s.add(n);
        for (int i = 0; i < moveFrom.length; i++) { s.remove(moveFrom[i]); s.add(moveTo[i]); }
        return new ArrayList<>(s);
    }
}
