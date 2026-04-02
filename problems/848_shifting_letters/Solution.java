class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        char[] arr = s.toCharArray();
        long total = 0;
        for (int i = arr.length - 1; i >= 0; i--) {
            total += shifts[i];
            arr[i] = (char) ((arr[i] - 'a' + total) % 26 + 'a');
        }
        return new String(arr);
    }
}
