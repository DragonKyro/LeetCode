import java.util.*;

class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] answer = new int[n + 1];
        for (int[] b : bookings) {
            answer[b[0] - 1] += b[2];
            if (b[1] < n) answer[b[1]] -= b[2];
        }
        for (int i = 1; i < n; i++) {
            answer[i] += answer[i - 1];
        }
        return Arrays.copyOf(answer, n);
    }
}
