import java.util.*;

class Solution {
    public int minimumIndex(List<Integer> nums) {
        Map<Integer,Integer> cnt = new HashMap<>();
        for (int n : nums) cnt.merge(n, 1, Integer::sum);
        int dom = 0, maxCnt = 0;
        for (var e : cnt.entrySet()) if (e.getValue() > maxCnt) { dom = e.getKey(); maxCnt = e.getValue(); }
        int left = 0, n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums.get(i) == dom) left++;
            if (left*2 > i+1 && (maxCnt-left)*2 > n-i-1) return i;
        }
        return -1;
    }
}
