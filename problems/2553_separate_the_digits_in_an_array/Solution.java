import java.util.*;

class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int n : nums) for (char c : String.valueOf(n).toCharArray()) res.add(c-'0');
        return res.stream().mapToInt(i->i).toArray();
    }
}
