class Solution {
    public String findLatestTime(String s) {
        char[] c = s.toCharArray();
        if (c[0] == '?') c[0] = (c[1] == '?' || c[1] <= '1') ? '1' : '0';
        if (c[1] == '?') c[1] = c[0] == '1' ? '1' : '9';
        if (c[3] == '?') c[3] = '5';
        if (c[4] == '?') c[4] = '9';
        return new String(c);
    }
}
