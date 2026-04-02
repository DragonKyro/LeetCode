class Solution {
    public String reverseOnlyLetters(String s) {
        char[] arr = s.toCharArray();
        int left = 0, right = arr.length - 1;
        while (left < right) {
            if (!Character.isLetter(arr[left])) left++;
            else if (!Character.isLetter(arr[right])) right--;
            else {
                char tmp = arr[left];
                arr[left++] = arr[right];
                arr[right--] = tmp;
            }
        }
        return new String(arr);
    }
}
