class Solution {
    public boolean isValid(String s) {
        StringBuilder stack = new StringBuilder();
        for (char c : s.toCharArray()) {
            stack.append(c);
            int n = stack.length();
            if (n >= 3 && stack.substring(n - 3).equals("abc"))
                stack.delete(n - 3, n);
        }
        return stack.length() == 0;
    }
}
