import java.util.*;

class Solution {
    public int maximizeGreatness(int[] nums) {
        Arrays.sort(nums);
        int j = 0;
        for (int n : nums) if (n > nums[j]) j++;
        return j;
    }
}
