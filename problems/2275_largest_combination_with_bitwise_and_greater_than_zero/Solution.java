class Solution {
    public int largestCombination(int[] candidates) {
        int result = 0;
        for (int bit = 0; bit < 24; bit++) {
            int count = 0;
            for (int c : candidates) if ((c & (1 << bit)) != 0) count++;
            result = Math.max(result, count);
        }
        return result;
    }
}
