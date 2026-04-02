class Solution {
    public int maxDivScore(int[] nums, int[] divisors) {
        int bestD = divisors[0], bestCnt = -1;
        for (int d : divisors) {
            int cnt = 0; for (int n : nums) if (n % d == 0) cnt++;
            if (cnt > bestCnt || (cnt == bestCnt && d < bestD)) { bestD = d; bestCnt = cnt; }
        }
        return bestD;
    }
}
