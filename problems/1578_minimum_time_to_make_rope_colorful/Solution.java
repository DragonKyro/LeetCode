class Solution {
    public int minCost(String colors, int[] neededTime) {
        int total = 0, i = 0;
        while (i < colors.length()) {
            int j = i, groupSum = 0, groupMax = 0;
            while (j < colors.length() && colors.charAt(j) == colors.charAt(i)) {
                groupSum += neededTime[j];
                groupMax = Math.max(groupMax, neededTime[j]);
                j++;
            }
            total += groupSum - groupMax;
            i = j;
        }
        return total;
    }
}
