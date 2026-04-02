class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int longest = releaseTimes[0];
        char result = keysPressed.charAt(0);
        for (int i = 1; i < releaseTimes.length; i++) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            if (duration > longest || (duration == longest && keysPressed.charAt(i) > result)) {
                longest = duration;
                result = keysPressed.charAt(i);
            }
        }
        return result;
    }
}
