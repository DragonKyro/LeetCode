class Solution {
    public int trap(int[] height) {
        int l = 0, r = height.length - 1, leftMax = 0, rightMax = 0, res = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                leftMax = Math.max(leftMax, height[l]);
                res += leftMax - height[l];
                l++;
            } else {
                rightMax = Math.max(rightMax, height[r]);
                res += rightMax - height[r];
                r--;
            }
        }
        return res;
    }
}
