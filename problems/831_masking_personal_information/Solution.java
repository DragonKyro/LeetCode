class Solution {
    public String maskPII(String s) {
        if (s.contains("@")) {
            s = s.toLowerCase();
            int at = s.indexOf('@');
            return s.charAt(0) + "*****" + s.substring(at - 1);
        }
        StringBuilder digits = new StringBuilder();
        for (char c : s.toCharArray()) if (Character.isDigit(c)) digits.append(c);
        String local = "***-***-" + digits.substring(digits.length() - 4);
        if (digits.length() == 10) return local;
        return "+" + "*".repeat(digits.length() - 10) + "-" + local;
    }
}
