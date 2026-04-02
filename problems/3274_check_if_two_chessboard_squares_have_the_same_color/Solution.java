class Solution {
    public boolean checkTwoChessboards(String c1, String c2) {
        return (c1.charAt(0) + c1.charAt(1)) % 2 == (c2.charAt(0) + c2.charAt(1)) % 2;
    }
}
