class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int lo = 0, hi = numbers.length - 1;
        while (lo < hi) {
            int s = numbers[lo] + numbers[hi];
            if (s == target) return new int[]{lo + 1, hi + 1};
            else if (s < target) lo++;
            else hi--;
        }
        return new int[]{};
    }
}
