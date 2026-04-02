import java.util.*;

class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums.length; i += 2)
            for (int j = 0; j < nums[i]; j++) res.add(nums[i+1]);
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}
