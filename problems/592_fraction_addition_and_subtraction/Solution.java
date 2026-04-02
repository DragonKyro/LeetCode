class Solution {
    public String fractionAddition(String expression) {
        long num = 0, den = 1;
        int i = 0, n = expression.length();
        while (i < n) {
            int sign = 1;
            if (expression.charAt(i) == '+' || expression.charAt(i) == '-') {
                if (expression.charAt(i) == '-') sign = -1;
                i++;
            }
            long numer = 0;
            while (i < n && Character.isDigit(expression.charAt(i)))
                numer = numer * 10 + (expression.charAt(i++) - '0');
            numer *= sign;
            i++; // skip '/'
            long denom = 0;
            while (i < n && Character.isDigit(expression.charAt(i)))
                denom = denom * 10 + (expression.charAt(i++) - '0');
            num = num * denom + numer * den;
            den *= denom;
            long g = gcd(Math.abs(num), Math.abs(den));
            num /= g; den /= g;
        }
        if (den < 0) { num = -num; den = -den; }
        return num + "/" + den;
    }
    private long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
}
