import java.util.*;

class Solution {
    int[] tree;
    int n;
    void update(int i, int d) { for (i++;i<=n;i+=i&(-i)) tree[i]+=d; }
    int query(int i) { int s=0; for (i++;i>0;i-=i&(-i)) s+=tree[i]; return s; }
    public List<Integer> countOfPeaks(int[] nums, int[][] queries) {
        n = nums.length; tree = new int[n+1];
        boolean[] peaks = new boolean[n];
        for (int i=1;i<n-1;i++) if (nums[i]>nums[i-1]&&nums[i]>nums[i+1]) { peaks[i]=true; update(i,1); }
        List<Integer> res = new ArrayList<>();
        for (int[] q : queries) {
            if (q[0]==1) {
                int l=q[1],r=q[2];
                res.add(r-l<2?0:query(r-1)-query(l));
            } else {
                int idx=q[1]; nums[idx]=q[2];
                for (int i=Math.max(1,idx-1);i<Math.min(n-1,idx+2);i++) {
                    boolean now=nums[i]>nums[i-1]&&nums[i]>nums[i+1];
                    if (peaks[i]&&!now) { update(i,-1); peaks[i]=false; }
                    else if (!peaks[i]&&now) { update(i,1); peaks[i]=true; }
                }
            }
        }
        return res;
    }
}
