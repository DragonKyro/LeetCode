class Solution {
    public int maximumLength(int[] nums) {
        int even = 0, odd = 0;
        for (int x : nums) { if (x%2==0) even++; else odd++; }
        int alt = 0, last = -1;
        for (int x : nums) {
            if (last == -1 || x%2 != last) { alt++; last = x%2; }
        }
        return Math.max(Math.max(even, odd), alt);
    }
}
