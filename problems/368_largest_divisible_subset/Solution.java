import java.util.*;

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] dp = new int[n], parent = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(parent, -1);
        int maxIdx = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) maxIdx = i;
        }
        List<Integer> res = new ArrayList<>();
        while (maxIdx != -1) {
            res.add(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }
        Collections.reverse(res);
        return res;
    }
}
