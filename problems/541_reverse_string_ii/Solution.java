class Solution {
    public String reverseStr(String s, int k) {
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i += 2 * k) {
            int left = i, right = Math.min(i + k - 1, arr.length - 1);
            while (left < right) {
                char tmp = arr[left];
                arr[left++] = arr[right];
                arr[right--] = tmp;
            }
        }
        return new String(arr);
    }
}
