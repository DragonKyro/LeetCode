import java.util.*;

class Solution {
    public int countPairs(int[] nums) {
        int res = 0, n = nums.length;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (almostEqual(nums[i], nums[j])) res++;
        return res;
    }
    boolean almostEqual(int a, int b) {
        if (a == b) return true;
        String sa = String.format("%07d", a), sb = String.format("%07d", b);
        List<Integer> diff = new ArrayList<>();
        for (int i = 0; i < 7; i++)
            if (sa.charAt(i) != sb.charAt(i)) diff.add(i);
        return diff.size() == 2 && sa.charAt(diff.get(0))==sb.charAt(diff.get(1)) && sa.charAt(diff.get(1))==sb.charAt(diff.get(0));
    }
}
