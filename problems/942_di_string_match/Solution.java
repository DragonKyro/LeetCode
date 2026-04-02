class Solution {
    public int[] diStringMatch(String s) {
        int n = s.length(), low = 0, high = n;
        int[] result = new int[n + 1];
        for (int i = 0; i < n; i++) {
            result[i] = s.charAt(i) == 'I' ? low++ : high--;
        }
        result[n] = low;
        return result;
    }
}
