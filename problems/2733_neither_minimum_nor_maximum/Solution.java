import java.util.*;

class Solution {
    public int neitherMinNorMax(int[] nums) {
        if (nums.length < 3) return -1;
        int[] a = {nums[0], nums[1], nums[2]};
        Arrays.sort(a);
        return a[1];
    }
}
