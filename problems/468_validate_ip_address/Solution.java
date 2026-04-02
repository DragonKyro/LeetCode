class Solution {
    public String validIPAddress(String queryIP) {
        if (queryIP.contains(".")) {
            String[] parts = queryIP.split("\\.", -1);
            if (parts.length != 4) return "Neither";
            for (String part : parts) {
                if (part.isEmpty() || part.length() > 3) return "Neither";
                for (char c : part.toCharArray()) if (!Character.isDigit(c)) return "Neither";
                if (part.length() > 1 && part.charAt(0) == '0') return "Neither";
                if (Integer.parseInt(part) > 255) return "Neither";
            }
            return "IPv4";
        } else if (queryIP.contains(":")) {
            String[] parts = queryIP.split(":", -1);
            if (parts.length != 8) return "Neither";
            for (String part : parts) {
                if (part.isEmpty() || part.length() > 4) return "Neither";
                for (char c : part.toCharArray()) {
                    if (!Character.isDigit(c) && "abcdefABCDEF".indexOf(c) == -1) return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
}
