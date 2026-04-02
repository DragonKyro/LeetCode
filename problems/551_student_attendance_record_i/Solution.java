class Solution {
    public boolean checkRecord(String s) {
        int aCount = 0;
        for (char c : s.toCharArray()) if (c == 'A') aCount++;
        return aCount < 2 && !s.contains("LLL");
    }
}
