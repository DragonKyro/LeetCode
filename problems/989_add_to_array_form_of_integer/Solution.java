import java.util.*;

class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> result = new ArrayList<>();
        int i = num.length - 1, carry = k;
        while (i >= 0 || carry > 0) {
            if (i >= 0) carry += num[i--];
            result.add(0, carry % 10);
            carry /= 10;
        }
        return result;
    }
}
