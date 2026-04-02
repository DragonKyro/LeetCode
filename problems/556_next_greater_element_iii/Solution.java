import java.util.*;

class Solution {
    public int nextGreaterElement(int n) {
        char[] digits = String.valueOf(n).toCharArray();
        int i = digits.length - 2;
        while (i >= 0 && digits[i] >= digits[i + 1]) i--;
        if (i < 0) return -1;
        int j = digits.length - 1;
        while (digits[j] <= digits[i]) j--;
        char tmp = digits[i]; digits[i] = digits[j]; digits[j] = tmp;
        Arrays.sort(digits, i + 1, digits.length);
        long val = Long.parseLong(new String(digits));
        return val <= Integer.MAX_VALUE ? (int)val : -1;
    }
}
