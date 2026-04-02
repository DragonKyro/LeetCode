class Solution {
    public String largestTimeFromDigits(int[] arr) {
        int result = -1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++) {
                    if (i == j || j == k || i == k) continue;
                    int l = 6 - i - j - k;
                    int hours = arr[i] * 10 + arr[j];
                    int minutes = arr[k] * 10 + arr[l];
                    if (hours < 24 && minutes < 60)
                        result = Math.max(result, hours * 60 + minutes);
                }
        return result == -1 ? "" : String.format("%02d:%02d", result / 60, result % 60);
    }
}
