class Solution {
    public int maximumPopulation(int[][] logs) {
        int[] delta = new int[101];
        for (int[] log : logs) {
            delta[log[0] - 1950]++;
            delta[log[1] - 1950]--;
        }
        int maxPop = 0, maxYear = 1950, curr = 0;
        for (int i = 0; i < 101; i++) {
            curr += delta[i];
            if (curr > maxPop) { maxPop = curr; maxYear = 1950 + i; }
        }
        return maxYear;
    }
}
