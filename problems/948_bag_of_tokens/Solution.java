import java.util.*;

class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int left = 0, right = tokens.length - 1, score = 0, result = 0;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left++];
                result = Math.max(result, ++score);
            } else if (score > 0) {
                power += tokens[right--];
                score--;
            } else break;
        }
        return result;
    }
}
