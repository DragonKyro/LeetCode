class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int windowSize = n - k;
        int window = 0;
        for (int i = 0; i < windowSize; i++) window += cardPoints[i];
        int minWindow = window;
        int total = window;
        for (int i = windowSize; i < n; i++) {
            total += cardPoints[i];
            window += cardPoints[i] - cardPoints[i - windowSize];
            minWindow = Math.min(minWindow, window);
        }
        return total - minWindow;
    }
}
