class Solution {
    public String reverseVowels(String s) {
        char[] arr = s.toCharArray();
        String vowels = "aeiouAEIOU";
        int l = 0, r = arr.length - 1;
        while (l < r) {
            while (l < r && vowels.indexOf(arr[l]) == -1) l++;
            while (l < r && vowels.indexOf(arr[r]) == -1) r--;
            char t = arr[l]; arr[l++] = arr[r]; arr[r--] = t;
        }
        return new String(arr);
    }
}
