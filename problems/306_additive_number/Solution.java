class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        for (int i = 1; i <= n / 2; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(num, i, j)) return true;
            }
        }
        return false;
    }
    private boolean check(String num, int i, int j) {
        if (num.charAt(0) == '0' && i > 1) return false;
        if (num.charAt(i) == '0' && j - i > 1) return false;
        String a = num.substring(0, i), b = num.substring(i, j);
        int k = j;
        while (k < num.length()) {
            String c = add(a, b);
            if (!num.startsWith(c, k)) return false;
            k += c.length();
            a = b;
            b = c;
        }
        return k == num.length();
    }
    private String add(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int carry = 0, i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += a.charAt(i--) - '0';
            if (j >= 0) sum += b.charAt(j--) - '0';
            sb.append(sum % 10);
            carry = sum / 10;
        }
        return sb.reverse().toString();
    }
}
