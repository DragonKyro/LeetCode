class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        return Math.max(maxConsec(answerKey, k, 'T'), maxConsec(answerKey, k, 'F'));
    }
    private int maxConsec(String s, int k, char ch) {
        int left = 0, count = 0, result = 0;
        for (int right = 0; right < s.length(); right++) {
            if (s.charAt(right) != ch) count++;
            while (count > k) {
                if (s.charAt(left) != ch) count--;
                left++;
            }
            result = Math.max(result, right - left + 1);
        }
        return result;
    }
}
