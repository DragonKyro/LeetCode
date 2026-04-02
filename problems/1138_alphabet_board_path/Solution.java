class Solution {
    public String alphabetBoardPath(String target) {
        StringBuilder sb = new StringBuilder();
        int r = 0, c = 0;
        for (char ch : target.toCharArray()) {
            int idx = ch - 'a';
            int tr = idx / 5, tc = idx % 5;
            while (r > tr) { sb.append('U'); r--; }
            while (c > tc) { sb.append('L'); c--; }
            while (r < tr) { sb.append('D'); r++; }
            while (c < tc) { sb.append('R'); c++; }
            sb.append('!');
        }
        return sb.toString();
    }
}
