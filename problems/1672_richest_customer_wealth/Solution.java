class Solution {
    public int maximumWealth(int[][] accounts) {
        int max = 0;
        for (int[] customer : accounts) {
            int sum = 0;
            for (int account : customer) sum += account;
            max = Math.max(max, sum);
        }
        return max;
    }
}
