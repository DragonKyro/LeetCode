import java.util.*;

class Solution {
    public List<Long> minOperations(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int n = nums.length;
        long[] pre = new long[n+1];
        for (int i = 0; i < n; i++) pre[i+1] = pre[i] + nums[i];
        List<Long> ans = new ArrayList<>();
        for (int q : queries) {
            int idx = lowerBound(nums, q);
            long left = (long)q*idx - pre[idx];
            long right = (pre[n]-pre[idx]) - (long)q*(n-idx);
            ans.add(left+right);
        }
        return ans;
    }
    int lowerBound(int[] a, int t) { int lo=0,hi=a.length; while(lo<hi){int m=(lo+hi)/2;if(a[m]<t)lo=m+1;else hi=m;} return lo; }
}
