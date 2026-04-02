class Solution {
    public boolean digitCount(String num) {
        for (int i = 0; i < num.length(); i++) {
            int count = 0;
            for (char c : num.toCharArray()) if (c - '0' == i) count++;
            if (count != num.charAt(i) - '0') return false;
        }
        return true;
    }
}
