class Solution {
    public int myAtoi(String s) {
        s = s.trim();
        if (s.isEmpty()) return 0;
        int sign = 1, idx = 0;
        if (s.charAt(0) == '-' || s.charAt(0) == '+') {
            sign = s.charAt(0) == '-' ? -1 : 1;
            idx++;
        }
        long num = 0;
        while (idx < s.length() && Character.isDigit(s.charAt(idx))) {
            num = num * 10 + (s.charAt(idx) - '0');
            if (num * sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (num * sign < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            idx++;
        }
        return (int)(num * sign);
    }
}
