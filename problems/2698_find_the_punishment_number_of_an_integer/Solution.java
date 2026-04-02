class Solution {
    public int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) if (canPart(String.valueOf(i*i), i)) ans += i*i;
        return ans;
    }
    boolean canPart(String s, int target) {
        if (s.isEmpty()) return target == 0;
        for (int i = 1; i <= s.length(); i++) {
            int val = Integer.parseInt(s.substring(0, i));
            if (val <= target && canPart(s.substring(i), target-val)) return true;
        }
        return false;
    }
}
