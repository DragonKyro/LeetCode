class Solution {
    public int minMaxDifference(int num) {
        String s = String.valueOf(num);
        String mx = s;
        for (char c : s.toCharArray()) if (c != '9') { mx = s.replace(c, '9'); break; }
        String mn = s.replace(s.charAt(0), '0');
        return Integer.parseInt(mx) - Integer.parseInt(mn);
    }
}
