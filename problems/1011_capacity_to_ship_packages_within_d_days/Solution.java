class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left = 0, right = 0;
        for (int w : weights) { left = Math.max(left, w); right += w; }
        while (left < right) {
            int mid = (left + right) / 2;
            int d = 1, cur = 0;
            for (int w : weights) {
                if (cur + w > mid) { d++; cur = 0; }
                cur += w;
            }
            if (d <= days) right = mid;
            else left = mid + 1;
        }
        return left;
    }
}
