class Solution {
    public String maxValue(String n, int x) {
        boolean isNeg = n.charAt(0) == '-';
        int start = isNeg ? 1 : 0;
        for (int i = start; i < n.length(); i++) {
            int digit = n.charAt(i) - '0';
            if (isNeg && digit > x) return n.substring(0, i) + x + n.substring(i);
            if (!isNeg && digit < x) return n.substring(0, i) + x + n.substring(i);
        }
        return n + x;
    }
}
